/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:59 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/13 16:28:00 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	print_file(int read_rt, char buff, int fd)
{
	while (read_rt > 0)
	{
		write(1, &buff, 1);
		read_rt = read(fd, &buff, 1);
	}
	close(fd);
}

void	repeat_order(void)
{
	int		fd;
	int		read_rt;
	char	buf;

	fd = 0;
	while (1)
	{
		read_rt = read(fd, &buf, 1);
		if (read_rt == 0)
			break ;
		write(1, &buf, 1);
	}
}

void	treat_error(char *error, char **av, int i)
{
	ft_putstr(basename(av[0]));
	write(2, ": ", 2);
	ft_putstr(av[i]);
	write(2, ": ", 2);
	ft_putstr(error);
	write(2, "\n", 1);
}

void	ft_cat(char **av, int i)
{
	char	buff;
	int		fd;
	int		read_rt;

	fd = open(av[i], O_RDONLY);
	if (fd == -1)
	{
		treat_error(strerror(errno), av, i);
		return ;
	}
	read_rt = read(fd, &buff, 1);
	if (read_rt < 0)
		treat_error(strerror(errno), av, i);
	print_file(read_rt, buff, fd);
	close(fd);
}
