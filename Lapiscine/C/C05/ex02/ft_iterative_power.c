/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:07:50 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/31 17:07:51 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	val;

	i = 1;
	val = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		val = val * nb;
		i++;
	}
	return (val);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_iterative_power(2, 5));
}*/