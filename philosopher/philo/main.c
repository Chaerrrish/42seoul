/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:36:29 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/19 23:10:14 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	are_you_die(t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&philo->dead_mutex);
	if (philo->dead_flag == 1)
		flag = 1;
	pthread_mutex_unlock(&philo->dead_mutex);
	return (flag);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_argv	*argv;

	philo = (t_philo *)arg;
	argv = philo->argv;
	while (are_you_die(philo) == 0)
	{
		pthread_mutex_unlock(&philo->dead_mutex);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("%ldms %d is eating\n", get_time() - philo->start, philo->id);
		usleep(argv->eat_time * 1000);
		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_eat = get_time();
		philo->eat_cnt++;
		pthread_mutex_unlock(&philo->meal_mutex);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(&philo->meal_mutex);
		if (argv->eat_num != -1 && philo->eat_cnt >= argv->eat_num)
		{
			philo->eat_flag = 1;
			pthread_mutex_unlock(&philo->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		printf("%ldms %d is sleeping\n", get_time() - philo->start, philo->id);
		usleep(argv->sleep_time * 1000);
		printf("%ldms %d is thinking\n", get_time() - philo->start, philo->id);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_argv			argv;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	if (ac < 5 || ac > 6)
		return (1);
	init_argv(ac, av, &argv);
	threads = malloc(sizeof(pthread_t) * argv.number_of_philo);
	philos = malloc(sizeof(t_philo) * argv.number_of_philo);
	forks = malloc(sizeof(pthread_mutex_t) * argv.number_of_philo);
	if (threads == NULL || philos == NULL || forks == NULL)
		print_error();
	init_philo(&argv, philos, threads, forks);
	run_philo(&argv, philos, threads);
	while (++i < argv.number_of_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philos[i].meal_mutex);
		pthread_mutex_destroy(&philos[i].dead_mutex);
	}
	free(threads);
	free(philos);
	free(forks);
	return (0);
}
