/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:01:49 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/05 17:01:50 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, ft_strlen(par[i].str));
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, ft_strlen(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
