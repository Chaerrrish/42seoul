/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:09:28 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/28 01:01:16 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data			data;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	
	if (ac != 5 || ac != 6)
		return (1);
	init_data(ac, av, &data);
	threads = malloc(sizeof(pthread_t) * data.philo_num);
	if (threads == NULL)
		return (1);
	init_mutex(&data, &philos, &forks);
	init_philo(&data, &philos, forks);
	run_philo(&data, philos, threads);
	
}
