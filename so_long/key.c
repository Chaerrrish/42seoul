/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:10:24 by chaoh             #+#    #+#             */
/*   Updated: 2024/02/22 15:04:44 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit(0);
}

static void	exit_check(t_param *param)
{
	if (param->map[param->p_y][param->p_x] == 'E')
		if (param->donut_cnt == param->donut)
			exit(0);
}

static int	move_check(t_param *param, int y, int x)
{
	if (param->map[y][x] == '1')
		return (0);
	else if (param->map[y][x] == 'E' && param->donut_cnt < param->donut)
		put_img(param, param->images.goal, x, y);
	else if (param->map[y][x] == 'C')
	{
		param->map[y][x] = '0';
		put_img(param, param->images.tiles, x, y);
		param->donut_cnt++;
	}
	ft_printf("Move : %d\n", ++param->move_cnt);
	return (1);
}

int	key_press(int keycode, t_param *param)
{
	put_img(param, param->images.tiles, param->p_x, param->p_y);
	if (param->map[param->p_y][param->p_x] == 'E')
		put_img(param, param->images.goal, param->p_x, param->p_y);
	if (keycode == KEY_W || keycode == UP)
		if (move_check(param, param->p_y - 1, param->p_x) == 1)
			param->p_y--;
	if (keycode == KEY_S || keycode == DOWN)
		if (move_check(param, param->p_y + 1, param->p_x) == 1)
			param->p_y++;
	if (keycode == KEY_D || keycode == RIGHT)
		if (move_check(param, param->p_y, param->p_x + 1) == 1)
			param->p_x++;
	if (keycode == KEY_A || keycode == LEFT)
		if (move_check(param, param->p_y, param->p_x - 1) == 1)
			param->p_x--;
	if (keycode == KEY_ESC)
		exit(0);
	if (param->donut_cnt > 0)
		put_img(param, param->images.donut_cat, param->p_x, param->p_y);
	else
		put_img(param, param->images.cat, param->p_x, param->p_y);
	exit_check(param);
	return (0);
}
