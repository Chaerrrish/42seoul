/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:22:29 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/30 18:31:07 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int ac, char **av, t_data *data)
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

int	init_mutex(t_data *data, pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->dead_mutex, NULL) == -1 || \
		pthread_mutex_init(&data->print_mutex, NULL) == -1 || \
		pthread_mutex_init(&data->meal_mutex, NULL) == -1)
		return (1);
	*forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (*forks == NULL)
		return (1);
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL) == -1)
			return (1);
		i++;
	}
	return (0);
}

int	init_philo(t_data *data, t_philo **philos, pthread_mutex_t *forks)
{
	int		i;
	long	start_time;

	i = 0;
	start_time = get_time() + data->philo_num;
	*philos = malloc(sizeof(t_philo) * data->philo_num);
	if (*philos == NULL)
		return (1);
	while (i < data->philo_num)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_cnt = 0;
		(*philos)[i].start = start_time;
		(*philos)[i].last_eat = start_time;
		(*philos)[i].left_fork = &forks[i];
		(*philos)[i].right_fork = &forks[(i + 1) % data->philo_num];
		(*philos)[i].data = data;
		i++;
	}
	return (0);
}
