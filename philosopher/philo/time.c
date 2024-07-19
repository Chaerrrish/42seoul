/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:35:31 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/18 20:35:14 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	mytime;
	long			result;

	gettimeofday(&mytime, NULL);
	result = ((size_t)mytime.tv_sec * 1000) + ((size_t)mytime.tv_usec / 1000);
	return (result);
}
