/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:13:27 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/31 19:13:32 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_map(char *map)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		map[i] = -1;
		i++;
	}
}

int	promising(char *map, int idx)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (map[i] == map[idx] || (map[i] - map[idx]) == i - idx)
			return(0);
		i++;
	}
	return (1);
}

void backtracking (char *map, int *cnt)
{
	int i;
	int j;

	cnt = 0;
	i = 0;

	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (promising(map, j) == 1)
			{
				map[i] = j;
				cnt++;
			}
			else
				alskdjweklr;
		}
	}
}

int ft_ten_queens_puzzle(void)
{
	char map[11];
	int cnt;

	cnt = 0;


}