/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:13:36 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 19:36:38 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define NONE -1

typedef pthread_mutex_t	t_mtx;

typedef enum e_io
{
	STDIN = 0,
	STDOUT = 1,
	STDERR = 2,
}			t_io;

typedef enum e_result
{
	SUCCESS = 1,
	FAILURE = 0,
}			t_resurl;

typedef enum e_button
{
	ON = 1,
	OFF = 0,
}			t_button;

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

typedef enum e_stomach
{
	HUNGRY,
	FULL,
}			t_stomach;

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
	pthread_t	philo;
	int			id;
	int			group;
	int			status;
	int			eat_count;
	long		dead_time;
	t_arg		*args;
	t_mtx		*forks;
	t_mtx		*lock;
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
int		mutex_init(t_mtx **mutex, int num);
int		philos_init(t_philo **philos, t_arg *args, t_mtx *forks, t_mtx *lock);
void	monitor_init(t_monitor *monitor, t_philo *philos);
void	do_pthread_create(t_philo *philos, t_monitor *monitor);
void	do_pthread_join(t_philo *philos, t_monitor *monitor);
void	mutex_destroy(t_mtx **mutex, int num);
void	*philosopher(void *arg);
void	*monitoring(void *arg);
long	get_time(void);
void	put_timestamp(int id, int status);
void	set_dead_time(t_philo *philo);
void	set_status(t_philo *philo, int status);
void	get_status(t_philo *philo, int *status);
void	get_fork(t_philo *philo, int fork_id);
void	drop_fork(t_philo *philo, int left_fork, int right_fork);
void	put_fork(t_philo *philo, t_hand *hand);
void	act_sleep(int act_time);
int		dead_or_alive(t_monitor *monitor, int num);
int		stomack_check(t_monitor *monitor, int num);
void	take_left_fork(t_philo *philo, t_hand *hand, int *l_status);
void	take_right_fork(t_philo *philo, t_hand *hand, int *l_status);
void	do_eat(t_philo *philo, int *l_status);
void	do_sleep(t_philo *philo, t_hand *hand, int *l_status);
void	ft_putendl_fd(char *s, int fd);
int		philo_atoi(const char *str);
int		ft_int_check(unsigned int input, unsigned int add, int minus);
int		ft_isspace(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

#endif
