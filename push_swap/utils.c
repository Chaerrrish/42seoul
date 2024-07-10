/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:47:08 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/08 16:36:50 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (-(value));
	return (value);
}

int	find_arr_index(int *arr, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int	find_index(t_deque *a, int n)
{
	t_node	*current;
	int		index;

	current = a->front;
	index = 0;
	while (current != NULL)
	{
		if (current->data == n)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

int	find_data(int *arr, int idx, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == idx)
			return (arr[i]);
		i++;
	}
	return (0);
}

void	all_free(t_deque *a, t_deque *b, int *arr)
{
	free_node(a);
	free_node(b);
	free(arr);
}
