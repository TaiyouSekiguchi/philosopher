/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:13:36 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/17 11:41:14 by tsekiguc         ###   ########.fr       */
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

typedef enum e_status
{
	THINK,
	TAKEN,
	EAT,
	SLEEP,
	DIE,
}			t_status;

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

typedef struct s_data
{
	int				id;
	int				group;
	int				status;
	int				status_sec;
	int				status_msec;
	t_arg			*arg;
	pthread_mutex_t	*fork;
}					t_data;

void	my_error(char *msg);
void	argv_atoi(t_arg *arg, int argc, char *argv[]);
void	fork_init(pthread_mutex_t **fork, int num);
void	data_init(t_data **data, t_arg *arg, pthread_mutex_t *fork);
void	philos_init(pthread_t **philos, int num);
void	*philosopher(void *arg);
void	set_status_time(t_data *data);

void	get_fork(t_data *data, int id, int fork_id);
void	sleep_and_drop_fork(t_data *data, int left_fork ,int right_fork);
void	set_status_and_put_timestamp(t_data *data, int id, int status);
void	put_timestamp(int id, char *msg);

#endif
