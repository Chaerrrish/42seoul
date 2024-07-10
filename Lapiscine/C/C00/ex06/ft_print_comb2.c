/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:44:05 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/04 13:24:20 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int n)
{
	char	first[2];
	char	second[2];
	int		m;

	m = n + 1;
	while (m < 100)
	{
		first[0] = n / 10 + '0';
		first[1] = n % 10 + '0';
		write(1, &first[0], 1);
		write(1, &first[1], 1);
		write(1, " ", 1);
		second[0] = m / 10 + '0';
		second[1] = m % 10 + '0';
		write(1, &second[0], 1);
		write(1, &second[1], 1);
		write(1, ",", 1);
		write(1, " ", 1);
		m++;
	}
}

void	ft_print_comb2(void)
{
	int	i;

	i = 0;
	while (i < 98)
	{
		print_num(i);
		i++;
	}
	write(1, "98 99", 5);
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
