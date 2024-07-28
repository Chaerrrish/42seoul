/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:36:09 by chaerin           #+#    #+#             */
/*   Updated: 2024/07/28 20:36:49 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct  s_data
{
	int				philo_num;
	int				life_time;
	int				eat_time;
	int				sleep_time;
	int				eat_num;
	int				stop_flag;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
}   t_data;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	long			start;
	long			last_eat;
	pthread_t		thread;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}   t_philo;

int	    ft_atoi(const char *str);
void	print_philo(t_philo *philo, int id, char *str);
long	get_time(void);
void    init_data(int ac, char **av, t_data *data);
void	init_mutex(t_data *data, t_philo *philos, pthread_mutex_t *forks);
void	init_philo(t_data *data, t_philo *philos, pthread_mutex_t *forks);
int 	get_fork(t_philo *philo);
int		eating(t_philo *philo, t_data *data);
int		sleeping(t_philo *philo, t_data *data);
int		thinking(t_philo *philo, t_data *data);
#endif