/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jss.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:13:40 by seungsje          #+#    #+#             */
/*   Updated: 2023/09/03 18:07:45 by seungsje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_up(int index, int size, char arr[][4], char ans[][4])	
{
	char	tmp;
	int		cnt;
	int		i;
	int 	x;

	i = 0;
	cnt = '0';
	tmp = '0';
	x = index % size;

	while (i < 4)
	{
		if (tmp < ans[i][x])
		{
			tmp = ans[i][x];
			cnt++;
			i++;
		}
		else
			i++;
	}
	if (cnt <= arr[0][x])
		return (1);
	return (0);
}

int	ft_check_down(int index, int size, char arr[][4], char ans[][4])
{
	char	tmp;
	int		cnt;
	int		i;

	i = 3;
	cnt = '0';
	tmp = '0';
	while (i >= 0)
	{
		if (tmp < ans[i][index % size])
		{
			tmp = ans[i][index % size];
			cnt++;
			i--;
		}
		else
			i--;
	}
	if (cnt <= arr[1][index % size])
		return (1);
	return (0);
}

int	ft_check_left(int index, int size, char arr[][4], char ans[][4])
{
	char	tmp;
	int		cnt;
	int		i;
	int		y;

	i = 0;
	cnt = '0';
	tmp = '0';
	y = index / size;

	while (i < 4)
	{
		if (tmp < ans[y][i])
		{
			tmp = ans[y][i];
			cnt++;
			i++;
		}
		else
			i++;
	}
	if (cnt <= arr[2][y])
		return (1);
	return (0);
}

int	ft_check_right(int index, int size, char arr[][4], char ans[][4])
{
	char	tmp;
	int		cnt;
	int		i;
	int		y;

	i = 3;
	y = index / size;
	cnt = '0';
	tmp = '0';
	while (i >= 0)
	{
		if (tmp < ans[y][i])
		{
			tmp = ans[y][i];
			cnt++;
			i--;
		}
		else
			i--;
	}
	if (cnt <= arr[3][y])
		return (1);
	return (0);
}
