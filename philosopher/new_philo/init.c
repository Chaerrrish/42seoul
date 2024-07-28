/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:22:29 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/28 00:58:27 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_data(int ac, char **av, t_data *data)
{
	data->stop_flag = 0;
	data->philo_num = ft_atoi(av[1]);
	data->life_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->eat_num = ft_atoi(av[5]);
	else
		data->eat_num = -1;
}

void	init_mutex(t_data *data, t_philo *philos, pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
	forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	while (i < data->philo_num)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
}

void	init_philo(t_data *data, t_philo **philos, pthread_mutex_t *forks)
{
	int		i;
	long	start_time;
	
	i = 0;
	start_time = get_time();
	philos = malloc(sizeof(pthread_t) * data->philo_num);
	while (i < data->philo_num)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_cnt = 0;
		(*philos)[i].start = start_time;
		(*philos)[i].last_eat = start_time;
		(*philos)[i].left_fork = &forks[i];
		(*philos)[i].right_fork = &forks[(i + 1) % data->philo_num];
		i++;
	}
}
