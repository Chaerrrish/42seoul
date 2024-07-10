/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:03:26 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/06 18:08:15 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	real_rb(t_deque *b, int rb_cnt)
{
	if (rb_cnt < 0)
	{
		rb_cnt = -rb_cnt;
		while (rb_cnt > 0)
		{
			rrb(b);
			rb_cnt--;
		}
	}
	else
	{
		while (rb_cnt > 0)
		{
			rb(b);
			rb_cnt--;
		}
	}
}

void	real_ra(t_deque *a, int ra_cnt)
{
	if (ra_cnt < 0)
	{
		ra_cnt = -ra_cnt;
		while (ra_cnt > 0)
		{
			rra(a);
			ra_cnt--;
		}
	}
	else
	{
		while (ra_cnt > 0)
		{
			ra(a);
			ra_cnt--;
		}
	}
}

void	b_to_a(t_deque *a, t_deque *b, int ra_cnt, int rb_cnt)
{
	real_rb(b, rb_cnt);
	real_ra(a, ra_cnt);
	pa(a, b);
}
