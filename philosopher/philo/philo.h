/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:26:21 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/17 19:49:53 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_argv
{
	int	number_of_philo;
	int	life_time;
	int	eat_time;
	int	sleep_time;
	int	eat_num;
}	t_argv;

typedef struct s_philo
{
	int		philo_num;
	int		eat_cnt;
	t_argv	*argv;
}	t_philo;

void	print_error(void);
void	*philo_routine(void *arg);
void	init_argv(int ac, char **av, t_argv *argv);
void	init_philo(t_argv *argv, t_philo *philos, pthread_t *threads);

#endif