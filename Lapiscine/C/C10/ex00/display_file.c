/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:15:31 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/13 23:54:16 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	read_file(int read_rt, char buff, int fd)
{
	while (read_rt > 0)
	{
		write(1, &buff, 1);
		read_rt = read(fd, &buff, 1);
	}
}

int	main(int ac, char **av)
{
	int		fd;
	int		read_rt;
	char	buff;

	if (ac < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	else if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	read_rt = read(fd, &buff, 1);
	if (fd < 0 || read_rt == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	read_file(read_rt, buff, fd);
	close(fd);
	return (0);
}
