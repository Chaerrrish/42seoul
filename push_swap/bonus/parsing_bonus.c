/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:17:40 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/08 18:40:33 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	change_num(char *str)
{
	long long	num;
	long long	flag;
	int			i;

	i = 0;
	flag = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		print_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		print_error();
	if (num * flag > 2147483647 || num * flag < -2147483648)
		print_error();
	return (num * flag);
}

void	check_arr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{	
				free(arr);
				print_error();
			}
			j++;
		}
		i++;
	}
}

int	parsing(int ac, char **av, t_deque *a)
{
	t_node	*node;
	char	**tmp;
	int		i;
	int		j;
	int		size;

	i = 1;
	size = 0;
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0)
			print_error();
		tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j] != NULL)
		{
			node = init_node(change_num(tmp[j]));
			push_rear(a, node);
			size++;
			j++;
		}
		free_arr(tmp);
		i++;
	}
	return (size);
}

int	*push_arr(t_deque *a, int size)
{
	int		*arr;
	t_node	*current;
	int		i;

	i = 0;
	current = a->front;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		print_error();
	while (current != NULL)
	{
		arr[i] = current->data;
		i++;
		current = current->next;
	}
	return (arr);
}
