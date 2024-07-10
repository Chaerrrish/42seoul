/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:11:13 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/07 21:09:09 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	empty_check(t_deque *a, t_deque *b)
{
	if (a->front == NULL && a->rear == NULL)
		return (0);
	if (b->front == NULL && b->rear == NULL)
		return (1);
	return (0);
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

void	final_check(t_deque *a, t_deque *b, int size)
{
	if (empty_check(a, b) == 1 && sort_check(a, size) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	commands(t_deque *a, t_deque *b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(a, b);
	else
		return (-1);
	return (0);
}
