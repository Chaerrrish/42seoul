/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:38:01 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/04 13:38:03 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	rt;

	*range = NULL;
	rt = max - min;
	if (min >= max)
		return (0);
	else
		*range = (int *)malloc(sizeof(int) * (unsigned int)(max - min));
	if (*range == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (rt);
}
/*
#include <stdio.h>
int main(void)
{
	int min = 15;
	int max = 30;
	int **range;
	range = (int **)malloc(sizeof(int *) * 1);
	printf("%d\n", ft_ultimate_range(range, min, max));

	return (0);
}*/