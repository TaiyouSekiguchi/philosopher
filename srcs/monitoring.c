/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:32:57 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 23:23:56 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		dead_check(t_monitor *monitor)
{
	struct timeval	tv;
	int				num;
	int				i;
	int				dead_sec;
	int				dead_msec;

	num = monitor->philos[0].arg->num_of_philos;
	i = 0;
	while (i < num)
	{

		pthread_mutex_lock(monitor->philos[i].lock);
		dead_sec = monitor->philos[i].dead_sec;
		dead_msec = monitor->philos[i].dead_msec;
		pthread_mutex_unlock(monitor->philos[i].lock);

		gettimeofday(&tv, NULL);
		if (dead_sec < tv.tv_sec
			|| (dead_sec == tv.tv_sec && dead_msec < (tv.tv_usec / 1000)))
			return (i);
		i++;
	}
	return (-1);
}

static void	dead_exit(t_philo *philos, int id)
{
	int	i;

	set_status_and_put_timestamp(philos, id, DIE);
	i = 0;
	while (i < philos[0].arg->num_of_philos)
	{
		pthread_detach(philos[i].philo);
		philos[i].loop = BREAK;
		i++;
	}
}

void	*monitoring(void *arg)
{
	t_monitor	*monitor;
	int			ret;

	usleep(200);
	monitor = (t_monitor *)arg;
	while (1)
	{
		ret = dead_check(monitor);
		if (ret >= 0)
		{
			dead_exit(monitor->philos, ret);
			break ;
		}
		usleep(100);
	}

	return (NULL);
}
