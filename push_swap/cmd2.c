/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:58:14 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 15:10:41 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	t_node	*temp;

	temp = pop_front(a);
	push_rear(a, temp);
	write(1, "ra\n", 3);
}

void	rb(t_deque *b)
{
	t_node	*temp;

	temp = pop_front(b);
	push_rear(b, temp);
	write(1, "rb\n", 3);
}

void	rr(t_deque *a, t_deque *b)
{
	t_node	*temp;

	temp = pop_front(a);
	push_rear(a, temp);
	temp = pop_front(b);
	push_rear(b, temp);
	write(1, "rr\n", 3);
}
