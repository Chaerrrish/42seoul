/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:10:11 by chaoh             #+#    #+#             */
/*   Updated: 2024/02/22 14:46:06 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char	*line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

char	**dup_map(t_param *param, char *map_file)
{
	int		i;
	int		j;
	int		fd;
	char	*buff;
	char	**rt_map;

	i = -1;
	fd = open(map_file, O_RDONLY);
	rt_map = (char **)malloc((sizeof(char *) * (param->y + 1)));
	while (++i < param->y)
	{
		buff = get_next_line(fd);
		rt_map[i] = (char *)malloc((sizeof(char *)
					* (count_line(buff) + 1)));
		j = -1;
		while (buff[++j] != '\n' && buff[j] != '\0')
		{
			rt_map[i][j] = buff[j];
		}
		rt_map[i][j] = '\0';
		free(buff);
	}
	rt_map[i] = NULL;
	return (rt_map);
}

int	count_map_size(t_param *param, int fd)
{
	char	*buff;
	int		i;

	i = -1;
	buff = get_next_line(fd);
	if (buff == NULL)
	{
		ft_printf("Map Error!\n");
		exit(1);
	}
	while (buff[++i] != '\n')
		param->x++;
	free(buff);
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		param->y++;
		free(buff);
		buff = get_next_line(fd);
	}
	if (param->x > 41 || param->y > 22)
		return (-1);
	free(buff);
	return (0);
}

void	free_map(t_param *param, char **map)
{
	int	i;

	i = 0;
	while (i < param->y)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}
