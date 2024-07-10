/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:09:18 by chaoh             #+#    #+#             */
/*   Updated: 2024/02/22 15:02:03 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rectangle_check(t_param *param)
{
	int	i;
	int	cnt_x;

	i = 1;
	cnt_x = count_line(param->map[0]);
	while (i < param->y)
	{
		if (cnt_x != count_line(param->map[i]))
			return (-1);
		else
			i++;
	}
	return (0);
}

static int	wall_check(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->x)
	{
		if (param->map[0][i] != '1' || param->map[param->y - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < param->y)
	{
		if (param->map[i][0] != '1' || param->map[i][param->x - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	count_objects(t_param *param)
{
	int		i;
	int		j;

	i = -1;
	while (++i < param->y)
	{
		j = -1;
		while (++j < param->x)
		{
			if (param->map[i][j] == 'P')
			{
				save_player_pos(param, j, i);
				param->p++;
			}
			else if (param->map[i][j] == 'E')
				param->e++;
			else if (param->map[i][j] == 'C')
				param->donut++;
			if (!(param->map[i][j] == 'E' || param->map[i][j] == 'C'\
					|| param->map[i][j] == 'P' || param->map[i][j] == '1'\
					|| param->map[i][j] == '0'))
				return (-1);
		}
	}
	return (0);
}

static void	dfs(int i, int j, t_param *param, char	**tmp_map)
{
	if (tmp_map[i][j] == '1' || tmp_map[i][j] == 'V')
		return ;
	if (tmp_map[i][j] == 'C' || tmp_map[i][j] == 'E')
		param->c_e++;
	tmp_map[i][j] = 'V';
	dfs(i, j + 1, param, tmp_map);
	dfs(i, j - 1, param, tmp_map);
	dfs(i + 1, j, param, tmp_map);
	dfs(i - 1, j, param, tmp_map);
}

int	map_check(t_param *param, char	*map_file)
{
	int		i;
	int		j;
	char	**tmp_map;

	i = -1;
	if (rectangle_check(param) == -1 || wall_check(param) == -1)
		return (-1);
	if (count_objects(param) == -1)
		return (-1);
	if (param->p != 1 || param->e != 1 || param->donut < 1)
		return (-1);
	tmp_map = dup_map(param, map_file);
	dfs(param->p_y, param->p_x, param, tmp_map);
	free_map(param, tmp_map);
	if (param->c_e != param->donut + 1)
		return (-1);
	return (0);
}
