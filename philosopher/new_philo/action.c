/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:05:11 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/28 20:33:00 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(500);
	pthread_mutex_lock(philo->left_fork);
	philo_print(philo, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	philo_print(philo, philo->id, "has taken a fork");
	return (1);
}

int	eating(t_philo *philo, t_data *data)
{
	int	result;

	result = 0;
	if (philo->data->stop_flag == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print_philo(philo, philo->id, "eating");
	usleep(data->eat_time * 1000);
	pthread_mutex_lock(&data->meal_mutex);
	philo->eat_cnt++;
	philo->last_eat = get_time();
	if (data->eat_num != -1 && philo->eat_cnt == data->eat_num)
		result = 0;
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (result);
}

int	sleeping(t_philo *philo, t_data *data)
{
	if (data->stop_flag == 1)
		return (0);
	print_philo(philo, philo->id, "is sleeping");
	usleep(data->sleep_time * 1000);
	return (1);
}

int	thinking(t_philo *philo, t_data *data)
{
	if (data->stop_flag == 1)
		return (0);
	print_philo(philo, philo->id, "is thinking");
	usleep(500);
	return (1);
}
