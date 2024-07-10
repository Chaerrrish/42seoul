/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:18:05 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 14:36:00 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_ra(t_deque *a, int b_data)
{
	int	loc_a;
	int	min_idx;

	loc_a = -1;
	min_idx = 0;
	find_loc_a(a, b_data, &loc_a, &min_idx);
	if (loc_a == -1)
		loc_a = min_idx;
	if (loc_a > a->size / 2)
		return (-(a->size - loc_a));
	return (loc_a);
}

void	find_loc_a(t_deque *a, int b_data, int *loc_a, int *min_idx)
{
	int		i;
	int		diff;
	int		min;
	t_node	*current;

	i = 0;
	min = 2147483647;
	diff = 2147483647;
	current = a->front;
	while (current != NULL)
	{
		if (current->data > b_data && current->data - b_data < diff)
		{
			diff = current->data - b_data;
			*loc_a = i;
		}
		if (min > current->data)
		{
			min = current->data;
			*min_idx = i;
		}
		i++;
		current = current->next;
	}
}

int	count_rb(t_deque *b, int idx)
{
	int	cnt;

	if (b->size / 2 < idx)
		cnt = -(b->size - idx);
	else
		cnt = idx;
	return (cnt);
}

void	greedy(t_deque *a, t_deque *b)
{
	t_cmds	cmds;
	t_node	*current;

	while (b->size > 0)
	{
		cmds.ra_cnt = 0;
		cmds.rb_cnt = 0;
		current = b->front;
		find_min_cmds(a, b, &cmds, current);
		b_to_a(a, b, cmds.ra_cnt, cmds.rb_cnt);
	}
	sort_final(a);
}

void	find_min_cmds(t_deque *a, t_deque *b, t_cmds *cmds, t_node *current)
{
	int	i;
	int	min;
	int	cur_ra_cnt;
	int	cur_rb_cnt;
	int	cur_cmd_cnt;

	i = 0;
	min = 2147483647;
	while (current != NULL)
	{
		cur_ra_cnt = count_ra(a, current->data);
		cur_rb_cnt = count_rb(b, i);
		cur_cmd_cnt = ft_abs(cur_ra_cnt) + ft_abs(cur_rb_cnt);
		if (cur_cmd_cnt < min)
		{
			min = cur_cmd_cnt;
			cmds->ra_cnt = cur_ra_cnt;
			cmds->rb_cnt = cur_rb_cnt;
		}
		current = current->next;
		i++;
	}
}
