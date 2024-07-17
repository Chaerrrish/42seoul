/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:36:29 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/17 19:53:12 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(void)
{
	printf("Error\n");
	exit(1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	value;

	i = 0;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			print_error();
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(value));
}

void	*philo_routine(void *arg)
{
}

int	main(int ac, char **av)
{
	t_argv		argv;
	t_philo		*philos;
	pthread_t	*threads;

	if (ac < 5)
		return (1);
	init_argv(ac, av, &argv);
	threads = malloc(sizeof(pthread_t) * argv.number_of_philo);
	philos = malloc(sizeof(t_philo) * argv.number_of_philo);
	if (threads == NULL || philos == NULL)
		print_error();
	return (0);
}
