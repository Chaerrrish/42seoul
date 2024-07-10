/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:30:13 by seungsje          #+#    #+#             */
/*   Updated: 2023/09/03 18:01:05 by seungsje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	arr[4][4];

	if (argc != 2)
		return (1);
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = argv[1][j * 2 + (i * 8)];
			if (arr[i][j] < '1' || arr[i][j] > '4')
				return (1);
			j++;
		}
		i++;
	}
	if (*(argv[1] + 31) != '\0')
		return (1);
	ft_loop_start(arr);
}
