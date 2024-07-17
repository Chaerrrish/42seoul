/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:46:11 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/17 19:47:53 by chaerin          ###   ########.fr       */
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

void	init_philo(t_argv *argv, t_philo *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < argv->number_of_philo)
	{
		philos[i].philo_num = i + 1;
		philos[i].eat_cnt = 0;
		philos[i].argv = argv;
		if (pthread_create(&threads[i], NULL, philo_routine, &philos[i]) != 0)
			print_error();
	}
}
