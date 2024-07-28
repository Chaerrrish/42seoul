/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:01:19 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/28 20:55:19 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo *philos, t_data *data)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(&data->dead_mutex);
		if (data->stop_flag == 1)
		{
			pthread_mutex_unlock(&data->dead_mutex);
		}	break ;
		pthread_mutex_unlock(&data->dead_mutex);
		i = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(&data->meal_mutex);
			if (get_time() - philos[i].last_eat > data->life_time)
			{
				pthread_mutex_unlock(&data->meal_mutex);
				print_philo(&philos[i], philos[i].id, "died");
				pthread_mutex_lock(&data->dead_mutex);
				data->stop_flag = 1;
				pthread_mutex_unlock(&data->dead_mutex);
				break ;
			}
			pthread_mutex_unlock(&data->meal_mutex);
			i++;
		}
		usleep(10);
	}
}


void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		if (get_fork(philo) == 0)
			break ;
		if (eating(philo, data) == 0)
			break ;
		if (sleeping(philo, data) == 0)
			break ;
		if (thinking(philo, data) == 0)
			break ;
	}
	return (NULL);
}

void	run_philo(t_data *data, t_philo *philos, pthread_t *threads)
{
	int i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_create(&threads[i], NULL, philo_routine, &philos[i]);
		i++;
	}
	monitoring(philos, data);
	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}