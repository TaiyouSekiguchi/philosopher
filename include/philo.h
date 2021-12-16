/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:13:36 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 10:02:25 by tsekiguc         ###   ########.fr       */
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

#define PHILOS	5
#define DELAY	5000
#define FOOD	50

typedef struct s_data
{
	int	num_of_phils;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_must_eat;
}				t_data;


void	*philosopher(void *id);
void	get_chopstick(int phil, int c, char *hand);
void	put_chopstick(int c1 ,int c2);
int		food_on_table(void);

#endif
