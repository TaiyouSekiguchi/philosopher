/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status_and_put_timestamp.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:49:26 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 23:04:03 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_status(t_philo *philo, int status, char **msg)
{
	if (status == THINK)
		*msg = "is thinking";
	else if (status == EAT)
	{
		//philo->eat_count++;
		set_dead_time(philo);
		*msg = "is eating";
	}
	else if (status == SLEEP)
		*msg = "is sleeping";
	else if (status == TAKEN)
		*msg = "has taken a fork";
	else if (status == DIE)
		*msg = "died";
	else
		*msg = "WHAT!!??";
	pthread_mutex_lock(philo->lock);
	philo->status = status;
	pthread_mutex_unlock(philo->lock);
}

static void	put_timestamp(int id, char *msg)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld%03u %d %s\n", tv.tv_sec, tv.tv_usec / 1000, id, msg);
}

void	set_status_and_put_timestamp(t_philo *philo, int id, int status)
{
	char	*msg;

	msg = NULL;
	set_status(philo, status, &msg);
	put_timestamp(id, msg);
}
