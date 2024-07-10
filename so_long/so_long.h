/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:03:35 by chaoh             #+#    #+#             */
/*   Updated: 2024/02/22 15:07:53 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "get_next_lines/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define UP          		126
# define DOWN        		125
# define LEFT        		123
# define RIGHT       		124		
# define PRESS_RED_BUTTON	17

typedef struct s_images{
	void	*cat;
	void	*donut;
	void	*donut_cat;
	void	*goal;
	void	*tiles;
	void	*wall;
}			t_images;

typedef struct s_param{
	int			fd;
	int			x;
	int			y;
	int			p;
	int			e;
	int			c_e;
	int			p_x;
	int			p_y;
	int			exit_x;
	int			exit_y;
	int			move_cnt;
	int			donut_cnt;
	int			donut;
	char		**map;
	void		*mlx;
	void		*win;
	t_images	images;
}				t_param;

//map.c
int		count_line(char	*line);
char	**dup_map(t_param *param, char *map_file);
int		count_map_size(t_param *param, int fd);
void	free_map(t_param *param, char **map);

//check_map.c
int		map_check(t_param *param, char	*map_file);

//show_map.c
void	put_img(t_param *param, void	*img_ptr, int x, int y);
int		set_img_ptr(t_param *param);
void	show_background(t_param *param);
void	save_player_pos(t_param *param, int j, int i);

//key.c
int		key_press(int keycode, t_param *param);
int		close_window(void);

#endif