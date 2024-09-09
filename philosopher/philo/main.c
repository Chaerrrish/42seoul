/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:09:28 by chaerin           #+#    #+#             */
/*   Updated: 2024/09/07 16:29:51 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

void	monitoring(t_philo *philos, t_data *data)
{
	while (1)
	{
		if (check_stop_flag(data))
			break ;
		if (check_philos_state(philos, data))
			break ;
		ft_usleep(1, data);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (get_time() < philo->start)
		usleep(100);
	if (philo->id % 2 == 0)
		ft_usleep(data->eat_time / 2, data);
	while (1)
	{
		if (get_fork(philo, data) == 0)
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
	int	i;

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

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;

	if (ac < 5 || ac > 6)
		return (1);
	if (init_data(ac, av, &data))
	{
		printf("Error\n");
		return (1);
	}
	threads = malloc(sizeof(pthread_t) * data.philo_num);
	if (threads == NULL)
		return (1);
	if (init_mutex(&data, &forks) || init_philo(&data, &philos, forks))
		return (1);
	run_philo(&data, philos, threads);
	destroy_mutex(&data, forks);
	free(threads);
	free(philos);
	free(forks);
	return (0);
}
