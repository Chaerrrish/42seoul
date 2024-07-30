/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:05:11 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/30 16:24:30 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork(t_philo *philo, t_data *data)
{
	if (check_stop_flag(data))
		return (0);
	if (philo->data->philo_num == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_philo(philo, philo->id, "has taken a fork");
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	if (philo->id % 2 == 0)
		usleep(500);
	pthread_mutex_lock(philo->left_fork);
	print_philo(philo, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_philo(philo, philo->id, "has taken a fork");
	return (1);
}

int	eating(t_philo *philo, t_data *data)
{
	int	result;

	result = 1;
	if (check_stop_flag(data))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print_philo(philo, philo->id, "is eating");
	usleep(data->eat_time * 1000);
	pthread_mutex_lock(&data->meal_mutex);
	philo->eat_cnt++;
	philo->last_eat = get_time();
	if (data->eat_num != -1 && philo->eat_cnt >= data->eat_num)
		result = 0;
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (check_stop_flag(data))
		result = 0;
	return (result);
}

int	sleeping(t_philo *philo, t_data *data)
{
	if (check_stop_flag(data))
		return (0);
	print_philo(philo, philo->id, "is sleeping");
	usleep(data->sleep_time * 1000);
	return (1);
}

int	thinking(t_philo *philo, t_data *data)
{
	if (check_stop_flag(data))
		return (0);
	print_philo(philo, philo->id, "is thinking");
	usleep(500);
	return (1);
}
