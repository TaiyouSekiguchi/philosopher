/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:13:36 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 22:07:15 by tsekiguc         ###   ########.fr       */
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
# define OFF -1

typedef pthread_mutex_t t_mtx;

typedef enum e_result
{
	SUCCESS = 1,
	FAILURE = 0,
}			t_resurl;

typedef enum e_status
{
	THINK,
	TAKEN_LEFT,
	TAKEN_RIGHT,
	EAT,
	SLEEP,
	DIE,
	GYM,
}			t_status;

typedef enum e_group
{
	EVEN,
	ODD,
}			t_group;

typedef enum e_handling
{
	EMPTY,
	HOLD,
}			t_handling;

typedef enum e_doa
{
	DEAD,
	ALIVE,
}			t_doa;

typedef struct s_arg
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_times_must_eat;
}				t_arg;

typedef struct s_fork
{
	t_mtx		*forks;
	int			*fork_flags;
}				t_fork;

typedef struct s_lock
{
	t_mtx		*locks;
	t_mtx		common_lock;
}				t_lock;

typedef struct s_time
{
	long		sec;
	long		msec;
}				t_time;

typedef struct s_philo
{
	pthread_t	philo;
	int			id;
	int			group;
	int			status;
	int			eat_count;
	t_time		dead;
	t_fork		*forks;
	t_arg		*args;
	t_mtx		*lock;
	t_mtx		*common_lock;
}				t_philo;

typedef struct s_monitor
{
	pthread_t	monitor;
	t_philo		*philos;
}				t_monitor;

typedef struct s_hand
{
	int			left;
	int			right;
	int			left_status;
	int			right_status;
}				t_hand;


void	add_eat_count(t_philo *philo);
int		argv_atoi(t_arg *arg, int argc, char *argv[]);
int		fork_init(t_fork *forks, int num);
int		lock_init(t_lock *locks, int num);
int		philos_init(t_philo **philos, t_arg *args, t_fork *forks, t_lock *lock);
void	monitor_init(t_monitor *monitor, t_philo *philos);
int		do_pthread_create(t_philo *philos, t_monitor *monitor);
int		do_pthread_join(t_philo *philos, t_monitor *monitor);
int		fork_destroy(t_fork *forks, int num);
int		lock_destroy(t_lock *locks, int num);
void	*philosopher(void *arg);
void	*monitoring(void *arg);
void	put_timestamp(int id, int status);
void	set_dead_time(t_philo *philo);
void	set_status(t_philo *philo, int status);
void	get_status(t_philo *philo, int *status);
void	get_fork(t_philo *philo, int fork_id);
void	drop_fork(t_philo *philo, int left_fork ,int right_fork);
void	put_fork(t_philo *philo, t_hand *hand, int id);
void	on_fork_flag(t_philo *philo, int fork_position);
void	off_fork_flag(t_philo *philo, int left_fork, int right_fork);
void	now_eating(int time_to_eat);
void	now_sleeping(int time_to_sleep);
int		dead_or_alive(t_monitor *monitor, int num);


#endif
