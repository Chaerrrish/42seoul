/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:52:22 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 15:37:54 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_front(t_deque *q, t_node *x)
{
	q->size++;
	x->prev = NULL;
	if (q->size == 1)
	{
		q->front = x;
		q->rear = x;
		x->next = NULL;
		return ;
	}
	else
	{
		x->next = q->front;
		q->front->prev = x;
		q->front = x;
	}
}

void	push_rear(t_deque *q, t_node *x)
{
	if (q == NULL || x == NULL)
		return ;
	q->size++;
	x->next = NULL;
	if (q->rear == NULL)
	{
		q->front = x;
		q->rear = x;
		x->prev = NULL;
		return ;
	}
	q->rear->next = x;
	x->prev = q->rear;
	q->rear = x;
}

t_node	*pop_front(t_deque *q)
{
	t_node	*temp;

	if (q->front == NULL)
		return (NULL);
	temp = q->front;
	q->size--;
	if (q->size == 0)
	{
		q->front = NULL;
		q->rear = NULL;
		return (temp);
	}
	else
	{
		q->front = q->front->next;
		temp->next = NULL;
		q->front->prev = NULL;
		return (temp);
	}
	return (NULL);
}

t_node	*pop_rear(t_deque *q)
{
	t_node	*temp;

	if (q->rear == NULL)
		return (NULL);
	temp = q->rear;
	q->size--;
	if (q->size == 0)
	{
		q->front = NULL;
		q->rear = NULL;
		return (temp);
	}
	else
	{
		q->rear = q->rear->prev;
		temp->prev = NULL;
		q->rear->next = NULL;
		return (temp);
	}
	return (NULL);
}
