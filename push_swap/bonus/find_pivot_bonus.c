/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:05:45 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/07 17:19:29 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	insertion_sort(int *arr, int n)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
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

void	input_index(t_deque *a, int *arr)
{
	t_node	*current;
	int		idx;

	current = a->front;
	while (current != NULL)
	{
		idx = find_arr_index(arr, current->data, a->size);
		current->index = idx;
		current = current->next;
	}
}

void	find_pivot(t_deque *a, int *arr, int size)
{
	int	interval;

	interval = size / 3;
	insertion_sort(arr, size);
	input_index(a, arr);
	a->pivot1 = interval;
	a->pivot2 = (interval * 2);
}
