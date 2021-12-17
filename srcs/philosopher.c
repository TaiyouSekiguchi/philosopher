/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:12:04 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/17 11:46:18 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_data			*data;
	int				id;
	int				left_fork;
	int				right_fork;

	data = (t_data *)arg;
	id = data->id;
	set_status_time(data);
	set_status_and_put_timestamp(data, id, THINK);

	left_fork = id + 1;
	right_fork = id;
	if (left_fork == data->arg->num_of_philos)
		left_fork = 0;

	while (1)
	{
		usleep(100);
		if (data->group == EVEN)
		{
			get_fork(data, id, left_fork);
			get_fork(data, id, right_fork);
		}
		else
		{
			get_fork(data, id, right_fork);
			get_fork(data, id, left_fork);
		}
		set_status_and_put_timestamp(data, id, EAT);
		usleep(data->arg->time_to_eat * 1000);

		sleep_and_drop_fork(data, left_fork, right_fork);

		set_status_and_put_timestamp(data, id, THINK);
	}

	return (NULL);
}
