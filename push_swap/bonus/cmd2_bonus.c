/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:58:14 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 16:26:40 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_deque *a)
{
	t_node	*temp;

	temp = pop_front(a);
	push_rear(a, temp);
}

void	rb(t_deque *b)
{
	t_node	*temp;

	temp = pop_front(b);
	push_rear(b, temp);
}

void	rr(t_deque *a, t_deque *b)
{
	t_node	*temp;

	temp = pop_front(a);
	push_rear(a, temp);
	temp = pop_front(b);
	push_rear(b, temp);
}
