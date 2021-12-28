/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:32:57 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 18:49:47 by tsekiguc         ###   ########.fr       */
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

void	*monitoring(void *arg)
{
	t_monitor	*monitor;
	int			num;
	int			eat_count_flag;

	monitor = (t_monitor *)arg;
	num = monitor->philos[0].args->num_of_philos;
	if (monitor->philos[0].args->num_of_times_must_eat != NONE)
		eat_count_flag = ON;
	else
		eat_count_flag = OFF;
	first_dead_time_set(monitor, num);
	usleep(1000);
	while (1)
	{
		if (dead_or_alive(monitor, num) == DEAD)
			break ;
		if (eat_count_flag == ON && stomack_check(monitor, num) == FULL)
			break ;
		usleep(500);
	}
	return (NULL);
}
