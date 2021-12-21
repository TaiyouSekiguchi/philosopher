/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:13:36 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 23:02:38 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <sys/time.h>

#include "libft.h"

# define NONE -1

typedef enum e_status
{
	THINK,
	TAKEN,
	EAT,
	SLEEP,
	DIE,
}			t_status;

typedef enum e_loop
{
	GO,
	BREAK,
}			t_loop;

typedef enum e_group
{
	EVEN,
	ODD,
}			t_group;

typedef struct s_arg
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_times_must_eat;
}				t_arg;

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	int				group;
	int				loop;
	int				eat_count;
	int				dead_sec;
	int				dead_msec;
	t_arg			*arg;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*lock;
}					t_philo;


typedef struct s_monitor
{
	pthread_t	monitor;
	t_philo		*philos;
}				t_monitor;


void	my_error(char *msg);
void	argv_atoi(t_arg *arg, int argc, char *argv[]);
void	fork_init(pthread_mutex_t **fork, int num);
void	fork_destroy(pthread_mutex_t **fork, int num);
void	philos_init(t_philo **philos, t_arg *arg, pthread_mutex_t *fork, pthread_mutex_t *lock);
void	*philosopher(void *arg);
void	set_dead_time(t_philo *philo);

void	get_fork(t_philo *philo, int id, int fork_id);
void	sleep_and_drop_fork(t_philo *philo, int left_fork ,int right_fork);
void	set_status_and_put_timestamp(t_philo *philo, int id, int status);
void	*monitoring(void *arg);
void	monitor_init(t_monitor *monitor, t_philo *philos);
void	philos_destroy(t_philo **philos);
void	do_pthread_create(t_philo *philos, t_monitor *monitor);
	
#endif
