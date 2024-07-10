/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:06:16 by chaoh             #+#    #+#             */
/*   Updated: 2024/05/14 15:15:07 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include "Libft/libft.h"

typedef struct s_data
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
	int		infile;
	int		outfile;
	char	*full_cmd1;
	char	*full_cmd2;
}				t_data;

void	handle_error(char *str);
char	**path_parsing(char **env);
void	param_is_free(char **str);

#endif