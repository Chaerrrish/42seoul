 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:34:31 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/09 16:34:32 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}
/*
int func(int n)
{
	if (n > 0)
		return (1);
	else
		return (0);
}

#include <stdio.h>
int main(void)
{
	int (*f)(int);
	f = func;
	int tab[7] = {-1, -2, -3, -4, 1, 2, 3};
	int length = 7;

	int *arr = ft_map(tab, length, f);
	for(int i = 0; i < length; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}*/