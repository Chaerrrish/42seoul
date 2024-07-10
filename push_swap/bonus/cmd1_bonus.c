/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:17:34 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 16:26:32 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	pa(t_deque *a, t_deque *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = pop_front(b);
	push_front(a, temp);
}

void	pb(t_deque *a, t_deque *b)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = pop_front(a);
	push_front(b, temp);
}
