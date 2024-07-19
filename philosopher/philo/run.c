/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:24:29 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/19 23:24:39 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_argv *argv, t_philo *philos)
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
				printf("%ldms %d died\n", get_time() - philos->start,
					philos->id);
				pthread_mutex_lock(&philos[i].dead_mutex);
				philos[i].dead_flag = 1;
				pthread_mutex_unlock(&philos[i].dead_mutex);
				pthread_mutex_unlock(&philos[i].meal_mutex);
				return ;
			}
			cnt = philos[i].eat_cnt;
			if (get_time() - philos->start > argv->life_time \
				&& cnt < argv->eat_num && argv->eat_num != -1)
			{
				printf("%ldms %d died\n", get_time() - philos->start,
					philos->id);
				pthread_mutex_lock(&philos[i].dead_mutex);
				philos[i].dead_flag = 1;
				pthread_mutex_unlock(&philos[i].dead_mutex);
				pthread_mutex_unlock(&philos[i].meal_mutex);
				return ;
			}
			if (philos[i].eat_flag == 1)
			{
				pthread_mutex_unlock(&philos[i].meal_mutex);
				return ;
			}
			pthread_mutex_unlock(&philos[i].meal_mutex);
			i++;
		}
	}
}

void	run_philo(t_argv *argv, t_philo *philos, pthread_t *threads)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	monitoring(argv, philos);
	while (i < argv->number_of_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	i = 0;
	flag = 1;
	while (i > argv->number_of_philo)
	{
		if (philos[i].eat_flag != 1)
			flag = 0;
		i++;
	}
	if (flag == 1)
		printf("All philosophers are full!\n");
}
