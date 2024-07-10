/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:18:37 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/30 14:18:38 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(char *arr, int i)
{
	while (i >= 0)
	{
		write(1, &arr[i], 1);
		if (i == 0)
			break ;
		i--;
	}
}

void	print_real_number(int nb, char *arr)
{
	int	n;
	int	i;

	i = 0;
	while (1)
	{
		n = nb % 10;
		nb = nb / 10;
		arr[i] = n + '0';
		if (nb != 0)
		{
			i++;
		}
		else if (nb == 0)
			break ;
	}
	print_number(arr, i);
}

void	ft_putnbr(int nb)
{
	char	arr[10];

	if (nb < 0 && nb != -2147483648)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
		print_real_number(nb, arr);
	write(1, "\n", 1);
}
