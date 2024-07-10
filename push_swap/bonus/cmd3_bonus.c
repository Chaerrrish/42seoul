/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:00:03 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 20:03:13 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_deque *a)
{
	t_node	*temp;

	temp = pop_rear(a);
	push_front(a, temp);
}

void	rrb(t_deque *b)
{
	t_node	*temp;

	temp = pop_rear(b);
	push_front(b, temp);
}

void	rrr(t_deque *a, t_deque *b)
{
	t_node	*temp;

	temp = pop_rear(a);
	push_front(a, temp);
	temp = pop_rear(b);
	push_front(b, temp);
}
