/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:20:14 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/04 13:24:13 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int n, int *arr, int pos)
{
	int	i;

	if (pos == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
}

void	ft_combn(int n, int *arr)
{
	int	i;
	int	max;

	i = n - 1;
	max = 9;
	while (arr[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	arr[i] += 1;
	while (i < n)
	{
		arr[i + 1] = arr[i] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	ft_print(n, arr, 0);
	while (arr[0] != 10 - n)
	{
		if (arr[n - 1] != 9)
		{
			arr[n - 1] += 1;
		}
		else
		{
			ft_combn(n, arr);
		}
		ft_print(n, arr, 1);
	}
}

int main(void)
{
    ft_print_combn(5);
    return (0);
}
