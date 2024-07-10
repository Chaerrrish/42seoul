/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:43:14 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/25 22:40:53 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(char *arr)
{
	char	sep[2];

	sep[0] = ',';
	sep[1] = ' ';
	write(1, arr, 3);
	if (arr[0] != '7' || arr[1] != '8' || arr[2] != '9')
		write(1, sep, 2);
}

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = '0';
	while (arr[0] <= '7')
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= '8')
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= '9')
			{
				print_num(arr);
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}*/
