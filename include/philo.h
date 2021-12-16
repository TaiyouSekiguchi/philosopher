/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:13:36 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 13:20:39 by tsekiguc         ###   ########.fr       */
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

typedef struct s_data
{
	int				id;
	int				status;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_must_eat;
	pthread_mutex_t	*chopstick;
}				t_data;

void	*philosopher(void *arg);
void	get_chopstick(t_data *data, int id, int cs_num);
void	put_chopstick(pthread_mutex_t *chopstick, int left_cs ,int right_cs);
void	my_error(char *msg);
void	set_status_and_put_timestamp(t_data *data, int id, int status);

#endif
