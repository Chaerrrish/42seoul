/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:46:11 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/19 22:45:51 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_argv(int ac, char **av, t_argv *argv)
{
	argv->number_of_philo = ft_atoi(av[1]);
	argv->life_time = ft_atoi(av[2]);
	argv->eat_time = ft_atoi(av[3]);
	argv->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		argv->eat_num = ft_atoi(av[5]);
	else
		argv->eat_num = -1;
}

void	init_philo(t_argv *argv, t_philo *philos, pthread_t *threads, \
					pthread_mutex_t *forks)
{
	int		i;
	long	start_time;

	i = -1;
	start_time = get_time();
	while (++i < argv->number_of_philo)
		pthread_mutex_init(&forks[i], NULL);
	i = 0;
	while (i < argv->number_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].eat_cnt = 0;
		philos[i].eat_flag = 0;
		philos[i].dead_flag = 0;
		philos[i].argv = argv;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % argv->number_of_philo];
		philos[i].start = start_time;
		philos[i].last_eat = start_time;
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		pthread_mutex_init(&philos[i].dead_mutex, NULL);
		if (pthread_create(&threads[i], NULL, philo_routine, &philos[i]) != 0)
			print_error();
		i++;
	}
}
