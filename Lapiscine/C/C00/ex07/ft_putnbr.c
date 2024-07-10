/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:57:58 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/04 13:24:06 by chaoh            ###   ########.fr       */
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

void	print_int_min(void)
{
	write(1, "-", 1);
	write(1, "2", 1);
	write(1, "147483648", 9);
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
		print_int_min();
	else
		print_real_number(nb, arr);
}

/*
int	main(void)
{
	ft_putnbr(0);
	write(1, "\n", 2);
	ft_putnbr(-128);
	write(1, "\n", 2);
	ft_putnbr(2147483647);
	write(1, "\n", 2);
	ft_putnbr(-2147483648);
	return (0);
}*/
