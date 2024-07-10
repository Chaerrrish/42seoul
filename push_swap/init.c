/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:44:22 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 15:12:37 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque *a, t_deque *b)
{
	a->front = NULL;
	a->rear = NULL;
	a->size = 0;
	a->pivot1 = 0;
	a->pivot2 = 0;
	b->front = NULL;
	b->rear = NULL;
	b->size = 0;
}

t_node	*init_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		print_error();
	node->prev = NULL;
	node->next = NULL;
	node->data = data;
	node->index = 0;
	return (node);
}
