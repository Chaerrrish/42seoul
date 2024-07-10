/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:17:34 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 15:10:33 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	t_node	*temp1;
	t_node	*temp2;

	if (a->size < 2)
		return ;
	temp1 = pop_front(a);
	temp2 = pop_front(a);
	push_front(a, temp1);
	push_front(a, temp2);
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	t_node	*temp1;
	t_node	*temp2;

	if (b->size < 2)
		return ;
	temp1 = pop_front(b);
	temp2 = pop_front(b);
	push_front(b, temp1);
	push_front(b, temp2);
	write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	t_node	*temp1;
	t_node	*temp2;

	if (a->size < 2)
		return ;
	temp1 = pop_front(a);
	temp2 = pop_front(a);
	push_front(a, temp1);
	push_front(a, temp2);
	if (b->size < 2)
		return ;
	temp1 = pop_front(b);
	temp2 = pop_front(b);
	push_front(b, temp1);
	push_front(b, temp2);
	write(1, "ss\n", 3);
}

void	pa(t_deque *a, t_deque *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = pop_front(b);
	push_front(a, temp);
	write(1, "pa\n", 3);
}

void	pb(t_deque *a, t_deque *b)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = pop_front(a);
	push_front(b, temp);
	write(1, "pb\n", 3);
}
