/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_or_alive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:36:39 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 18:36:22 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_dead_time(t_philo *philo, long *l_dead_time)
{
	pthread_mutex_lock(philo->lock);
	*l_dead_time = philo->dead_time;
	pthread_mutex_unlock(philo->lock);
}

static int	dead_time_cmp(long l_dead_time)
{
	long	now;

	now = get_time();
	if (l_dead_time < now)
		return (DEAD);
	return (ALIVE);
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

int	dead_or_alive(t_monitor *monitor, int num)
{
	long	l_dead_time;
	int		i;

	i = 0;
	while (i < num)
	{
		get_dead_time(&monitor->philos[i], &l_dead_time);
		if (dead_time_cmp(l_dead_time) == DEAD)
		{
			put_timestamp(i, DIE);
			all_status_die(monitor, num);
			return (DEAD);
		}
		i++;
	}
	return (ALIVE);
}
