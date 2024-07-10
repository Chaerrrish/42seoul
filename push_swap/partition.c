/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:19:38 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/07 17:10:57 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partitioning(t_deque *a, t_deque *b)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (a->front->index >= a->pivot2)
			ra(a);
		else if (a->front->index < a->pivot1)
		{
			pb(a, b);
			rb (b);
		}
		else if (a->front->index >= a->pivot1 && a->front->index < a->pivot2)
			pb(a, b);
		i++;
	}
	while (a->size > 0)
		pb(a, b);
}

void	sort_final(t_deque *a)
{
	t_node	*current;
	int		cnt;

	current = a->front;
	cnt = 0;
	while (current)
	{
		if (current->index == 0)
		{
			while (cnt > 0)
			{
				ra(a);
				cnt--;
			}
		}
		cnt++;
		current = current->next;
	}
}
