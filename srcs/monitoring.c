/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:32:57 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 17:43:45 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	first_dead_time_set(t_monitor *monitor, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		set_dead_time(&monitor->philos[i]);
		i++;
	}
}

void	get_eat_count(t_philo *philo, int *l_eat_count)
{
	pthread_mutex_lock(philo->lock);
	*l_eat_count = philo->eat_count;
	pthread_mutex_unlock(philo->lock);
}

void	all_status_gym(t_monitor *monitor, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		set_status(&monitor->philos[i], GYM);
		i++;
	}
}

int	stomack_check(t_monitor *monitor, int num)
{
	int	l_eat_count;
	int	i;

	i = 0;
	while (i < num)
	{
		get_eat_count(&monitor->philos[i], &l_eat_count);
		if (monitor->philos[i].args->num_of_times_must_eat > l_eat_count)
			return (0);
		i++;
	}
	all_status_gym(monitor, num);
	return (1);
}

void	*monitoring(void *arg)
{
	t_monitor	*monitor;
	int			num;
	int			eat_count_flag;

	//printf("monitor get ready\n");
	monitor = (t_monitor *)arg;
	num = monitor->philos[0].args->num_of_philos;
	if (monitor->philos[0].args->num_of_times_must_eat != NONE)
		eat_count_flag = 1;
	else
		eat_count_flag = 0;
	first_dead_time_set(monitor, num);
	usleep(1000);
	while (1)
	{
		if (dead_or_alive(monitor, num) == DEAD)
			break ;
		if (eat_count_flag && stomack_check(monitor, num))
			break ;
		usleep(100);
	}

	printf("monitor is exit\n");
	return (NULL);
}
