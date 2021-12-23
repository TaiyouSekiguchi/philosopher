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

static int		time_cmp(int dead_sec, int dead_msec)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (dead_sec < tv.tv_sec
		|| (dead_sec == tv.tv_sec && dead_msec < (tv.tv_usec / 1000)))
		return (1);
	return (0);
}

/*static void	check_fork_array(t_philo *philo)
{
	int	num;
	int	i;

	num = philo->arg->num_of_philos;

	pthread_mutex_lock(philo->lock);
	i = 0;
	while (i < num)
	{
		if (philo->fork_array[i] == 1)
		{
			pthread_mutex_unlock(&philo->fork[i]);
			philo->fork_array[i] = 0;
		}
		i++;
	}
	pthread_mutex_unlock(philo->lock);
}*/

static int		dead_check(t_monitor *monitor)
{
	int				num;
	int				i;
	int				dead_sec;
	int				dead_msec;
	int				ret;
	int				id;

	num = monitor->philos[0].arg->num_of_philos;
	i = 0;
	while (i < num)
	{
		get_dead_time(&monitor->philos[i], &dead_sec, &dead_msec);
		ret = time_cmp(dead_sec, dead_msec);
		if (ret)
		{
			id = i;
			set_status(&monitor->philos[id], DIE);
			put_timestamp(id, DIE);
			i = 0;
			while (i < num)
			{
				set_status(&monitor->philos[i], DIE);
				i++;
			}
			//check_fork_array(&monitor->philos[0]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	set_dead_time_all(t_monitor *monitor)
{
	int		num;
	int		i;

	num = monitor->philos[0].arg->num_of_philos;
	i = 0;
	while (i < num)
	{
		set_dead_time(&monitor->philos[i]);
		i++;
	}
}

void	*monitoring(void *arg)
{
	t_monitor	*monitor;

	//printf("monitor get ready\n");
	monitor = (t_monitor *)arg;
	set_dead_time_all(monitor);
	usleep(1000);
	while (1)
	{
		if (dead_check(monitor))
			break ;
		usleep(100);
	}

	printf("monitor is exit\n");
	return (NULL);
}
