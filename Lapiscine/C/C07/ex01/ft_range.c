/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:48:38 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/02 15:48:47 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	ptr = NULL;
	if (min >= max)
		return (ptr);
	else
		ptr = (int *)malloc(sizeof(int) * (unsigned int)(max - min));
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
int main(void)
{
	int min = 15;
	int max = 30;
	int *ptr;
	ptr = ft_range(min, max);
	for(int i = 0; i < max - min; i++)
	{
		printf("%d\n", ptr[i]);
	}

	return (0);
}*/