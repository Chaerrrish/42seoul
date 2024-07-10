/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:51:19 by seungsje          #+#    #+#             */
/*   Updated: 2023/09/03 18:24:06 by seungsje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_loop_start(char arr[][4])
{
	char	ans[4][4];
	int		index;
	int		size;

	index = 0;
	size = 4;
	init(ans);
	ft_loop(index, size, arr, ans);
}

int	ft_loop(int index, int size, char arr[][4], char ans[][4])
{
	int	i;
	int	result;

	result = 1;
	i = '0';
	while (++i < '5')
	{
		ans[index / size][index % size] = i;
		if (ft_check(index, size, arr, ans))
		{
			if (iscomplete(ans) == 1)
			{
				print_ans(ans);
				return (0);
			}
			else
			{
				result = ft_loop(index + 1, size, arr, ans);
				if (result == 0)
					return (0);
			}
		}
	}
	ans[index / size][index % size] = '0';
	return (1);
}

int	ft_check(int index, int size, char arr[][4], char ans[][4])
{	
	if (ft_check_up(index, size, arr, ans) == 0)
		return (0);
	if (ft_check_down(index, size, arr, ans) == 0)
		return (0);
	if (ft_check_left(index, size, arr, ans) == 0)
		return (0);
	if (ft_check_right(index, size, arr, ans) == 0)
		return (0);
	if (check_sudoku(index, size, ans) == 0)
		return (0);
	return (1);
}
