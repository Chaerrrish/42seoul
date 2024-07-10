/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaoh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:19:12 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/03 18:08:31 by seungsje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	init(char arr[][4])		//0으로 채워주는 함수
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	check_sudoku(int index, int size, char ans[][4])	//가로세로에 같은 수가 있는지 확인하는 함수
{
	int	i;
	int	x;
	int	y;

	x = index % size;
	y = index / size;
	i = 0;
	while (i < 4)
	{
		if (ans[y][i] == ans[y][x] && i != x)	//같은 수수가  존존재재하하면  0
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (ans[i][x] == ans[y][x] && i != y)
			return (0);
		i++;
	}
	return (1);
}

int	iscomplete(char ans[][4])	//배열이 완성이 되었는지 확인하는 함수
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ans[i][j] == '0')	//0이 하하나나라도 존존재재하하면  0 리턴
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_ans(char ans[][4])	//정답 배열 출력하는 함수
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &ans[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
