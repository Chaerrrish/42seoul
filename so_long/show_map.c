/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:10:05 by chaoh             #+#    #+#             */
/*   Updated: 2024/02/22 15:07:43 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_param *param, void	*img_ptr, int x, int y)
{
	mlx_put_image_to_window(param->mlx, param->win, img_ptr, 64 * x, 64 * y);
}

int	set_img_ptr(t_param *param)
{
	int	img_width;
	int	img_height;

	param->images.cat = mlx_xpm_file_to_image(param->mlx,
			"textures/cat.xpm", &img_width, &img_height);
	param->images.donut = mlx_xpm_file_to_image(param->mlx,
			"textures/small_donut.xpm", &img_width, &img_height);
	param->images.donut_cat = mlx_xpm_file_to_image(param->mlx,
			"textures/donut_cat.xpm", &img_width, &img_height);
	param->images.goal = mlx_xpm_file_to_image(param->mlx,
			"textures/80rainbow.xpm", &img_width, &img_height);
	param->images.wall = mlx_xpm_file_to_image(param->mlx,
			"textures/cactus.xpm", &img_width, &img_height);
	param->images.tiles = mlx_xpm_file_to_image(param->mlx,
			"textures/tiles.xpm", &img_width, &img_height);
	if (param->images.cat == NULL || param->images.donut == NULL
		|| param->images.donut_cat == NULL || param->images.goal == NULL
		|| param->images.wall == NULL || param->images.tiles == NULL)
	{
		ft_printf("Image Error!\n");
		return (-1);
	}
	return (0);
}

static void	show_object(t_param *param)
{
	int	i;
	int	j;

	i = -1;
	while (++i < param->y)
	{
		j = -1;
		while (++j < param->x)
		{
			if (param->map[i][j] == '0')
				put_img(param, param->images.tiles, j, i);
			if (param->map[i][j] == 'P')
				save_player_pos(param, j, i);
			if (param->map[i][j] == 'C')
			{
				put_img(param, param->images.donut, j, i);
				if (param->p_x == j && param->p_y == i)
					++param->donut_cnt;
			}
			if (param->map[i][j] == 'E')
				put_img(param, param->images.goal, j, i);
		}
	}
}

void	show_background(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (i < param->y)
	{
		j = 0;
		while (j < param->x)
		{
			put_img(param, param->images.tiles, j, i);
			if (param->map[i][j] == '1')
				put_img(param, param->images.wall, j, i);
			else if (param->map[i][j] == 'E')
			{
				param->exit_x = j;
				param->exit_y = i;
			}
			j++;
		}
		i++;
	}
	show_object(param);
}

void	save_player_pos(t_param *param, int j, int i)
{
	put_img(param, param->images.cat, j, i);
	param->p_x = j;
	param->p_y = i;
}
