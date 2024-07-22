/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:36:46 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/20 16:16:08 by chaerin          ###   ########.fr       */
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

void	print_philo(t_philo *philo, int id, char *str)
{
	pthread_mutex_lock(&philo->print_mutex);
	printf("%ldms %d %s\n", get_time() - philo->start, id, str);
	pthread_mutex_unlock(&philo->print_mutex);
}
