/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:23:22 by chaoh             #+#    #+#             */
/*   Updated: 2023/12/20 20:49:35 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*for_join(char **line, char *buff)
{
	char	*temp;

	temp = ft_strjoin((*line), buff);
	if (temp == NULL)
	{
		if ((*line))
			free((*line));
		(*line) = NULL;
		return (NULL);
	}
	free((*line));
	(*line) = NULL;
	return (temp);
}

char	*save_the_rest(char **line)
{
	char	*the_rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*line))
		return (NULL);
	while ((*line)[i] != '\0' && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
		i++;
	the_rest = (char *)malloc(sizeof(char) * (ft_strlen((*line)) - i + 1));
	if (the_rest == NULL)
		return (free_for_fail(*line));
	while ((*line)[i] != '\0')
		the_rest[j++] = (*line)[i++];
	the_rest[j] = '\0';
	free((*line));
	(*line) = NULL;
	return (the_rest);
}

char	*make_a_line(char **buffer_line)
{
	char	*rt_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*buffer_line)[i] != '\0' && (*buffer_line)[i] != '\n')
		i++;
	if (!(ft_strchr((*buffer_line), '\n')))
		rt_line = (char *)malloc(sizeof(char) * (i + 1));
	else
		rt_line = (char *)malloc(sizeof(char) * (i + 2));
	if (rt_line == NULL)
	{
		free((*buffer_line));
		(*buffer_line) = NULL;
		return (NULL);
	}
	i = 0;
	while ((*buffer_line)[i] != '\0' && (*buffer_line)[i] != '\n')
		rt_line[j++] = (*buffer_line)[i++];
	if ((*buffer_line)[i] == '\n')
		rt_line[j++] = '\n';
	rt_line[j] = '\0';
	return (rt_line);
}

char	*get_a_line(int fd, char **line)
{
	ssize_t	read_bytes;
	char	buff[BUFFER_SIZE + 1];

	if (!(*line))
	{
		(*line) = ft_strdup("");
		if ((*line) == NULL)
			return (NULL);
	}
	read_bytes = read(fd, buff, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		if (read_bytes == -1)
			return (free_for_fail((*line)));
		buff[read_bytes] = '\0';
		(*line) = for_join((line), buff);
		if ((*line) == NULL)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break ;
		read_bytes = read(fd, buff, BUFFER_SIZE);
	}
	if (ft_strlen((*line)) == 0)
		return (free_for_fail((*line)));
	return ((*line));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (buffer_line)
			free(buffer_line);
		buffer_line = NULL;
		return (NULL);
	}
	buffer_line = get_a_line(fd, &buffer_line);
	if (buffer_line == NULL)
		return (NULL);
	line = make_a_line(&buffer_line);
	if (line == NULL)
		return (NULL);
	buffer_line = save_the_rest(&buffer_line);
	if (buffer_line == NULL)
		return (line);
	return (line);
}
