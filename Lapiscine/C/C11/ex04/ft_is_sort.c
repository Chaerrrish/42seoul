/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:22:04 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/09 17:22:05 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	long	tmp;

	i = 0;
	tmp = 0;
	while (i < length - 1 && tmp == 0)
	{
		tmp = f(tab[i], tab[i + 1]);
		i++;
	}
	while (i < length - 1)
	{
		if ((f(tab[i], tab[i + 1]) * tmp < 0))
			return (0);
		i++;
	}
	return (1);
}
/*
int ft_intcmp(int a, int b)
{
	if(a < b)
		return (a - b);
	else if (a == b)
		return (0);
	else
		return (a - b);
}

#include <stdio.h>
int main(void)
{
	int (*f)(int, int);
	f = ft_intcmp;
	int arr1[7] = {1,2,3,3,-1,5,6};
	int arr2[7] = {};
	int arr3[7] = {9,6,5,8,7,4,8};

	printf("%d\n", ft_is_sort(arr1, 7, f));
	printf("%d\n", ft_is_sort(arr2, 0, f));
	printf("%d\n", ft_is_sort(arr3, 7, f));

	return (0);
}*/