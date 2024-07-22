/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:36:29 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/22 21:57:22 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_flag(t_philo *philos, int num_of_philos)
{
	int	i;
	int	dead_flag;

	i = 0;
	dead_flag = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_lock(&philos[i].dead_mutex);
		if (philos[i].dead_flag == 1)
		{
			dead_flag = 1;
			pthread_mutex_unlock(&philos[i].dead_mutex);
			break ;
		}
		pthread_mutex_unlock(&philos[i].dead_mutex);
		i++;
	}
	return (dead_flag);
}

int	eating(t_philo *philo, t_argv *argv)
{
	if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(philo->right_fork);
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(philo->left_fork);
    }

    print_philo(philo, philo->id, "is eating");
    usleep(argv->eat_time * 1000);

    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_eat = get_time();
    philo->eat_cnt++;
    pthread_mutex_unlock(&philo->meal_mutex);

    // 포크를 반대로 해제합니다.
    if (philo->id % 2 == 0)
    {
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
    }
    else
    {
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
    }

    pthread_mutex_lock(&philo->meal_mutex);
    if (argv->eat_num != -1 && philo->eat_cnt >= argv->eat_num)
    {
        philo->eat_flag = 1;
        pthread_mutex_unlock(&philo->meal_mutex);
        return (1);
    }
    pthread_mutex_unlock(&philo->meal_mutex);
    return (0);
}

void	destroy_mutex(t_argv *argv, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < argv->number_of_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philos[i].meal_mutex);
		pthread_mutex_destroy(&philos[i].print_mutex);
		pthread_mutex_destroy(&philos[i].dead_mutex);
		i++;
	}
	free(philos);
	free(forks);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_argv	*argv;

	philo = (t_philo *)arg;
	argv = philo->argv;
	while (1)
	{
		pthread_mutex_lock(&philo->dead_mutex);
		if (philo->dead_flag == 1)
		{
			pthread_mutex_unlock(&philo->dead_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->dead_mutex);
		if (eating(philo, argv) == 1)
			break ;
		print_philo(philo, philo->id, "is sleeping");
		usleep(argv->sleep_time * 1000);
		print_philo(philo, philo->id, "is thinking");
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_argv			argv;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;

	if (ac < 5 || ac > 6)
		return (1);
	init_argv(ac, av, &argv);
	threads = malloc(sizeof(pthread_t) * argv.number_of_philo);
	philos = malloc(sizeof(t_philo) * argv.number_of_philo);
	forks = malloc(sizeof(pthread_mutex_t) * argv.number_of_philo);
	if (threads == NULL || philos == NULL || forks == NULL)
		print_error();
	init_mutex(&argv, forks);
	init_philo(&argv, philos, threads, forks);
	run_philo(&argv, philos, threads);
	destroy_mutex(&argv, philos, forks);
	free(threads);
	return (0);
}
