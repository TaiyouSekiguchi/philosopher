/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_or_alive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:36:39 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/24 12:54:50 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_dead_time(t_philo *philo, t_time *l_dead)
{
	pthread_mutex_lock(philo->lock);
	l_dead->sec = philo->dead.sec;
	l_dead->msec = philo->dead.msec;
	pthread_mutex_unlock(philo->lock);
}

static int		time_cmp(t_time *l_dead)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (l_dead->sec < tv.tv_sec
		|| (l_dead->sec == tv.tv_sec && l_dead->msec < (tv.tv_usec / 1000)))
		return (1);
	return (0);
}

static void	all_status_die(t_monitor *monitor, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		set_status(&monitor->philos[i], DIE);
		i++;
	}
}

int		dead_or_alive(t_monitor *monitor, int num)
{
	t_time			l_dead;
	int				i;

	i = 0;
	while (i < num)
	{
		get_dead_time(&monitor->philos[i], &l_dead);
		if(time_cmp(&l_dead))
		{
			put_timestamp(i, DIE);
			all_status_die(monitor ,num);
			return (DEAD);
		}
		i++;
	}
	return (ALIVE);
}
