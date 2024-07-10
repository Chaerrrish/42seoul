/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:10:08 by chaoh             #+#    #+#             */
/*   Updated: 2024/02/22 14:57:46 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_param *param)
{
	param->x = 0;
	param->y = 1;
	param->p = 0;
	param->e = 0;
	param->c_e = 0;
	param->move_cnt = 0;
	param->donut = 0;
	param->donut_cnt = 0;
	param->exit_x = 0;
	param->exit_y = 0;
}

static	void	destroy_img_ptr(t_param *param)
{
	mlx_destroy_image(param->mlx, param->images.cat);
	mlx_destroy_image(param->mlx, param->images.donut);
	mlx_destroy_image(param->mlx, param->images.donut_cat);
	mlx_destroy_image(param->mlx, param->images.wall);
	mlx_destroy_image(param->mlx, param->images.tiles);
	mlx_destroy_image(param->mlx, param->images.goal);
}

static int	invaild_map_name(t_param *param, char *file_name)
{
	size_t	file_len;

	file_len = ft_strlen(file_name);
	if (file_len <= ft_strlen("maps/.ber"))
		return (-1);
	if (file_name[file_len - 1] != 'r' || file_name[file_len - 2] != 'e'
		|| file_name[file_len - 3] != 'b' || file_name[file_len - 4] != '.')
		return (-1);
	param->fd = open(file_name, O_RDONLY);
	if (param->fd < 0)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_param	param;

	init_game(&param);
	if (argc != 2 || argv[1] == NULL || invaild_map_name(&param, argv[1]) == -1 \
		|| count_map_size(&param, param.fd) == -1)
		return (ft_printf("Map Error!\n"), 1);
	param.map = dup_map(&param, argv[1]);
	if (param.map == NULL || map_check(&param, argv[1]) == -1)
	{
		ft_printf("Map Error!\n");
		exit(1);
	}
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, \
		param.x * 64, param.y * 64, "so_long");
	if (set_img_ptr(&param) == -1)
		return (1);
	show_background(&param);
	mlx_hook(param.win, 2, 0, &key_press, &param);
	mlx_hook(param.win, PRESS_RED_BUTTON, 0, &close_window, &param);
	mlx_loop(param.mlx);
	destroy_img_ptr(&param);
	close(param.fd);
	free_map(&param, param.map);
	return (0);
}
