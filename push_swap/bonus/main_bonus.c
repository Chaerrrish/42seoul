/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:17:49 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/08 16:40:18 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_node(t_deque *deque)
{
	t_node	*current;
	t_node	*tmp;

	current = deque->front;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

void	all_free(t_deque *a, t_deque *b, int *arr, char *cmd)
{
	free(cmd);
	free_node(a);
	free_node(b);
	free(arr);
}

int	execute_commands(t_deque *a, t_deque *b, int *arr, char *cmd)
{
	cmd = get_next_line(0);
	if (cmd == NULL)
		return (-1);
	if (commands(a, b, cmd) == -1)
	{
		all_free(a, b, arr, cmd);
		print_error();
	}
	free(cmd);
	return (0);
}

int	main(int ac, char **av)
{
	t_deque	a;
	t_deque	b;
	int		*arr;
	int		size;
	char	*cmd;

	cmd = NULL;
	if (ac < 2)
		return (0);
	init_deque(&a, &b);
	size = parsing(ac, av, &a);
	arr = push_arr(&a, size);
	check_arr(arr, size);
	find_pivot(&a, arr, size);
	while (1)
	{
		if (execute_commands(&a, &b, arr, cmd) == -1)
			break ;
	}
	final_check(&a, &b, size);
	all_free(&a, &b, arr, cmd);
	return (0);
}
