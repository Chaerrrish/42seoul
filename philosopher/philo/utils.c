/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:36:46 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/06 19:34:32 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time, t_data *data)
{
	long	finish;

	finish = get_time() + time;
	while (get_time() < finish)
	{
		if (check_stop_flag(data))
			break ;
		usleep(100);
	}
}

int	philo_atoi(const char *str, int *num)
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
			return (1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (value > 2147483647)
		return (1);
	*num = (int)value;
	return (0);
}

void	print_philo(t_philo *philo, int id, char *str)
{
	if (check_stop_flag(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d %s\n", get_time() - philo->start, id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

long	get_time(void)
{
	struct timeval	mytime;
	long			result;

	gettimeofday(&mytime, NULL);
	result = ((size_t)mytime.tv_sec * 1000) + ((size_t)mytime.tv_usec / 1000);
	return (result);
}
