/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:24:29 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/22 22:03:32 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring(t_argv *argv, t_philo *philos)
{
	int	i;
	int	cnt;

	while (1)
	{
		i = 0;
		while (i < argv->number_of_philo)
		{
			pthread_mutex_lock(&philos[i].meal_mutex);
			if (get_time() - philos[i].last_eat > argv->life_time)
			{
				print_philo(philos, philos[i].id, "died");
				pthread_mutex_lock(&philos[i].dead_mutex);
				philos[i].dead_flag = 1;
				pthread_mutex_unlock(&philos[i].dead_mutex);
				pthread_mutex_unlock(&philos[i].meal_mutex);
				return (1);
			}
			cnt = philos[i].eat_cnt;
			if (get_time() - philos->start > argv->life_time \
				&& cnt < argv->eat_num && argv->eat_num != -1)
			{
				pthread_mutex_lock(&philos[i].dead_mutex);
				print_philo(philos, philos[i].id, "died");
				philos[i].dead_flag = 1;
				pthread_mutex_unlock(&philos[i].dead_mutex);
				pthread_mutex_unlock(&philos[i].meal_mutex);
				return (1);
			}
			if (philos[i].eat_flag == 1)
			{
				pthread_mutex_unlock(&philos[i].meal_mutex);
				return (1);
			}
			pthread_mutex_unlock(&philos[i].meal_mutex);
			i++;
		}
	}
	return (0);
}

void	run_philo(t_argv *argv, t_philo *philos, pthread_t *threads)
{
	int	i;
	int	flag;

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
	// i = 0;
	// while (i < argv->number_of_philo)
	// {
	// 	pthread_join(threads[i], NULL);
	// 	i++;
	// }
	i = 0;
	flag = 1;
	while (i < argv->number_of_philo)
	{
		if (philos[i].eat_flag != 1)
			flag = 0;
		i++;
	}
	if (flag == 1)
		printf("All philosophers are full!\n");
}
