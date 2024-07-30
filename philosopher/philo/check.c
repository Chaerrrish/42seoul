/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:01:19 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/30 16:19:18 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_stop_flag(t_data *data)
{
	int	stop_flag;

	pthread_mutex_lock(&data->dead_mutex);
	stop_flag = data->stop_flag;
	pthread_mutex_unlock(&data->dead_mutex);
	return (stop_flag);
}

int	check_finished_philo(int finished_philo, t_data *data)
{
	if (data->eat_num != -1 && finished_philo == data->philo_num)
	{
		pthread_mutex_lock(&data->dead_mutex);
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		printf("All philosophers are full!\n");
		return (1);
	}
	return (0);
}

int	check_philo_full(t_philo *philo, t_data *data)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&data->meal_mutex);
	if (data->eat_num != -1 && philo->eat_cnt >= data->eat_num)
		result = 1;
	pthread_mutex_unlock(&data->meal_mutex);
	return (result);
}

int	check_philo_death(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->meal_mutex);
	if (get_time() - philo->last_eat > data->life_time)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		print_philo(philo, philo->id, "died");
		pthread_mutex_lock(&data->dead_mutex);
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

int	check_philos_state(t_philo *philos, t_data *data)
{
	int	i;
	int	finished_philo;

	i = 0;
	finished_philo = 0;
	while (i < data->philo_num)
	{
		if (check_philo_death(&philos[i], data))
			return (1);
		if (check_philo_full(&philos[i], data))
			finished_philo++;
		i++;
	}
	pthread_mutex_lock(&data->meal_mutex);
	if (data->eat_num != -1 && finished_philo == data->philo_num)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		pthread_mutex_lock(&data->dead_mutex);
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		printf("All philosophers are full!\n");
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}
