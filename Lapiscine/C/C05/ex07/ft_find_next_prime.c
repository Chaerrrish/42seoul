/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:33:02 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/31 18:33:04 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;
	unsigned int	unb;

	i = 2;
	unb = nb;
	if (nb <= 1)
	{
		return (0);
	}
	while (i * i <= unb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb) == 1)
		{
			return (nb);
			break ;
		}
		nb++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_find_next_prime(24));
	return (0);
}*/