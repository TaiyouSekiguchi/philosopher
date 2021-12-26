/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dead_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:49:11 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 23:15:13 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dead_time(t_philo *philo)
{
	struct timeval	tv;
	int				tmp;
	int				sec;
	int				msec;

	gettimeofday(&tv, NULL);
	tmp = (tv.tv_usec / 1000) + philo->args->time_to_die;
	sec = tmp / 1000;
	msec = tmp % 1000;

	pthread_mutex_lock(philo->lock);
	philo->dead.sec = tv.tv_sec + sec;
	philo->dead.msec = msec;
	pthread_mutex_unlock(philo->lock);
}
