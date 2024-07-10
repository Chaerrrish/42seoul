/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:30:55 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/03 18:23:48 by seungsje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>

void	init(char arr[][4]);
int		check_sudoku(int index, int size, char ans[][4]);
int		iscomplete(char ans[][4]);
void	print_ans(char ans[][4]);
void	ft_loop_start(char arr[][4]);
int		ft_loop(int index, int size, char arr[][4], char ans[][4]);
int		ft_check_up(int index, int size, char arr[][4], char ans[][4]);
int		ft_check_down(int index, int size, char arr[][4], char ans[][4]);
int		ft_check_left(int index, int size, char arr[][4], char ans[][4]);
int		ft_check_right(int index, int size, char arr[][4], char ans[][4]);
int		ft_check(int index, int size, char arr[][4], char ans[][4]);

#endif
