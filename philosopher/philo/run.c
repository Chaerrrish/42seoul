/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:24:29 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/24 15:20:12 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring(t_argv *argv, t_philo *philos)
{
	int	i;
	int	all_full;

	while (1)
	{
		i = 0;
		all_full = 1;
		while (i < argv->number_of_philo)
		{
			pthread_mutex_lock(&philos[i].meal_mutex);
			if (get_time() - philos[i].last_eat > argv->life_time)
			{
				pthread_mutex_lock(&philos[i].dead_mutex);
				philos[i].dead_flag = 1;
				pthread_mutex_unlock(&philos[i].dead_mutex);
				print_philo(philos, philos[i].id, "died");
				pthread_mutex_unlock(&philos[i].meal_mutex);
				return (1);
			}
			if (argv->eat_num != -1 && philos[i].eat_cnt < argv->eat_num)
				all_full = 0;
			pthread_mutex_unlock(&philos[i].meal_mutex);
			i++;
		}
		if (all_full == 1)
			return (1);
	}
	return (0);
}

void	run_philo(t_argv *argv, t_philo *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < argv->number_of_philo)
	{
		pthread_create(&threads[i], NULL, philo_routine, &philos[i]);
		i++;
	}
	if (monitoring(argv, philos) == 1)
	{
		i = 0;
		while (i < argv->number_of_philo)
		{
			pthread_mutex_lock(&philos[i].dead_mutex);
			philos[i].dead_flag = 1;
			pthread_mutex_unlock(&philos[i].dead_mutex);
			pthread_join(threads[i], NULL);
			i++;
		}
		return ;
	}
}
