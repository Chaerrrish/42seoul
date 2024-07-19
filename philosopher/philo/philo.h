/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:26:21 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/19 22:45:41 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

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
	int				id;
	int				eat_cnt;
	int				eat_flag;
	int				dead_flag;
	long			start;
	long			last_eat;
	t_argv			*argv;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t dead_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

long	get_time(void);
void	print_error(void);
int		ft_atoi(const char *str);
void	*philo_routine(void *arg);
void	monitoring(t_argv *argv, t_philo *philos);
void	init_argv(int ac, char **av, t_argv *argv);
void	init_philo(t_argv *argv, t_philo *philos, pthread_t *threads, \
					pthread_mutex_t *forks);
void	run_philo(t_argv *argv, t_philo *philos, pthread_t *threads);

#endif