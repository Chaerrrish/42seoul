/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:19:47 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/08 15:08:27 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	int		size;
	int		pivot1;
	int		pivot2;
	t_node	*front;
	t_node	*rear;
}	t_deque;

//main_bonus.c
void	print_error(void);

//parsing_bonus.c
int		parsing(int ac, char **av, t_deque *a);
int		*push_arr(t_deque *a, int size);
void	check_arr(int *arr, int size);
void	free_arr(char **arr);

//init_bonus.c
t_node	*init_node(int data);
void	init_deque(t_deque *a, t_deque *b);

//find_pivot.c
int		find_arr_index(int *arr, int n, int size);
void	find_pivot(t_deque *a, int *arr, int size);
void	input_index(t_deque *a, int *arr);
void	insertion_sort(int *arr, int n);

//checker_bonus.c
int		empty_check(t_deque *a, t_deque *b);
int		sort_check(t_deque *a, int size);
void	final_check(t_deque *a, t_deque *b, int size);
int		commands(t_deque *a, t_deque *b, char *cmd);

//deque_cmd_bonus.c
void	push_rear(t_deque *q, t_node *x);
void	push_front(t_deque *q, t_node *x);
t_node	*pop_front(t_deque *q);
t_node	*pop_rear(t_deque *q);

//bonus_cmds
void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);

#endif