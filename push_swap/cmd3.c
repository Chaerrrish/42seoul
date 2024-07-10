/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:00:03 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/03 16:45:09 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *a)
{
	t_node	*temp;

	temp = pop_rear(a);
	push_front(a, temp);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *b)
{
	t_node	*temp;

	temp = pop_rear(b);
	push_front(b, temp);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b)
{
	t_node	*temp;

	temp = pop_rear(a);
	push_front(a, temp);
	temp = pop_rear(b);
	push_front(b, temp);
	write(1, "rrr\n", 4);
}
