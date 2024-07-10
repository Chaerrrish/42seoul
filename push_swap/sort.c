/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:09:23 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/08 16:22:37 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_deque *a)
{
	t_node	*min_node;
	t_node	*current;

	min_node = a->front;
	current = a->front;
	while (current != NULL)
	{
		if (current->data < min_node->data)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	sort_two(t_deque *a)
{
	int	n1;
	int	n2;

	n1 = a->front->data;
	n2 = a->rear->data;
	if (n1 > n2)
		sa(a);
}

void	sort_three(t_deque *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->front->data;
	n2 = a->front->next->data;
	n3 = a->rear->data;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(a);
	if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a);
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		rra(a);
		sa(a);
	}
	if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a);
	if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		ra(a);
		sa(a);
	}
}

void	sort_four(t_deque *a, t_deque *b)
{
	t_node	*min_node;
	int		index;

	min_node = find_min(a);
	index = find_index(a, min_node->data);
	while (a->front != min_node)
	{
		if (index > a->size / 2)
			rra(a);
		else
			ra(a);
	}
	if (sort_check(a, 4) == 1)
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_deque *a, t_deque *b)
{
	t_node	*min_node;
	int		index;

	min_node = find_min(a);
	index = find_index(a, min_node->data);
	while (a->front != min_node)
	{
		if (index > a->size / 2)
			rra(a);
		else
			ra(a);
	}
	if (sort_check(a, 5) == 1)
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
