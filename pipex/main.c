/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:48:48 by chaoh             #+#    #+#             */
/*   Updated: 2024/05/14 15:45:45 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*find_route(t_data *data, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (data->path[i] != NULL)
	{
		tmp = ft_strjoin(data->path[i], "/");
		tmp = ft_strjoin(tmp, cmd);
		if (tmp == NULL)
		{
			free(tmp);
			handle_error("strjoin() failed");
		}
		if (access(tmp, X_OK) == 0)
			return (tmp);
		else
		{
			free(tmp);
			i++;
		}
	}
	return (NULL);
}

void	first_child(t_data *data, char **av, char **env, int *fd)
{
	data->infile = open(av[1], O_RDONLY, 0644);
	if (data->infile < 0)
		handle_error("infile open failed");
	data->full_cmd1 = find_route(data, data->cmd1[0]);
	if (data->full_cmd1 == NULL)
		handle_error("find_root() failed");
	close(fd[0]);
	if (dup2(data->infile, 0) == -1)
		handle_error("dup2() failed");
	if (dup2(fd[1], 1) == -1)
		handle_error("dup2() failed");
	close(fd[1]);
	close(data->infile);
	if (execve(data->full_cmd1, data->cmd1, env) < 0)
		handle_error("execve() failed");
}

void	second_child(t_data *data, char **av, char **env, int *fd)
{
	data->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->outfile < 0)
		handle_error("open() failed");
	data->full_cmd2 = find_route(data, data->cmd2[0]);
	close(fd[1]);
	if (dup2(data->outfile, 1) == -1)
		handle_error("dup2() failed");
	if (dup2(fd[0], 0) == -1)
		handle_error("dup2() failed");
	close(fd[0]);
	close(data->outfile);
	if (execve(data->full_cmd2, data->cmd2, env) == -1)
		handle_error("execve() failed");
}

void	make_pipe(t_data *data, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid1 = fork();
	if (pid1 > 0)
	{
		pid2 = fork();
		if (pid2 < 0)
			handle_error("fork() failled");
		else if (pid2 == 0)
			second_child(data, av, env, fd);
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
	else if (pid1 == 0)
		first_child(data, av, env, fd);
	else
		handle_error("fork() failled");
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
		return (1);
	data.cmd1 = ft_split(av[2], ' ');
	data.cmd2 = ft_split(av[3], ' ');
	data.path = path_parsing(env);
	make_pipe(&data, av, env);
	param_is_free(data.cmd1);
	param_is_free(data.cmd2);
	param_is_free(data.path);
	return (0);
}
