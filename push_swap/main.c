/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:17:49 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/11 20:45:28 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_under_6(t_deque *a, t_deque *b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

int	sort_check(t_deque *a, int size)
{
	t_node	*current;
	int		i;

	current = a->front;
	i = 0;
	while (i < size)
	{
		if (i != current->index)
			return (0);
		i++;
		current = current->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_deque	a;
	t_deque	b;
	int		*arr;
	int		size;

	if (ac < 2)
		return (0);
	init_deque(&a, &b);
	size = parsing(ac, av, &a);
	arr = push_arr(&a, size);
	check_arr(arr, size);
	find_pivot(&a, arr, size);
	if (sort_check(&a, size) != 1)
	{
		if (size <= 5)
			sort_under_6(&a, &b, size);
		else
		{
			partitioning(&a, &b);
			greedy(&a, &b);
		}
	}
	all_free(&a, &b, arr);
	return (0);
}
