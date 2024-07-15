/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:19:47 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/11 20:15:39 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./Libft/libft.h"

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

typedef struct s_cmds
{
	int	ra_cnt;
	int	rb_cnt;
}	t_cmds;

//main.c
void	print_error(void);
int		sort_check(t_deque *a, int size);
void	free_node(t_deque *deque);

//parsing.c
int		parsing(int ac, char **av, t_deque *a);
int		*push_arr(t_deque *a, int size);
void	check_arr(int *arr, int size);
int		change_num(char *str);

//utils.c
int		ft_abs(int value);
int		find_arr_index(int *arr, int n, int size);
int		find_index(t_deque *a, int n);
int		find_data(int *arr, int idx, int size);
void	all_free(t_deque *a, t_deque *b, int *arr);

//init.c
t_node	*init_node(int data);
void	init_deque(t_deque *a, t_deque *b);

//find_pivot.c
void	find_pivot(t_deque *a, int *arr, int size);

//deque_cmd.c
void	push_rear(t_deque *q, t_node *x);
void	push_front(t_deque *q, t_node *x);
t_node	*pop_front(t_deque *q);
t_node	*pop_rear(t_deque *q);

//sort.c
void	sort_two(t_deque *a);
void	sort_three(t_deque *a);
void	sort_four(t_deque *a, t_deque *b);
void	sort_five(t_deque *a, t_deque *b);

//partition.c
void	partitioning(t_deque *a, t_deque *b);
void	sort_final(t_deque *a);

//greedy.c
void	greedy(t_deque *a, t_deque *b);
void	find_loc_a(t_deque *a, int b_data, int *loc_a, int *min_idx);
void	b_to_a(t_deque *a, t_deque *b, int ra_cnt, int rb_cnt);
void	find_min_cmds(t_deque *a, t_deque *b, t_cmds *cmds, t_node *current);

//move.c
void	b_to_a(t_deque *a, t_deque *b, int ra_cnt, int rb_cnt);
void	real_rb(t_deque *b, int rb_cnt);
void	real_ra(t_deque *a, int ra_cnt);

//cmds
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
