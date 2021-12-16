/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:12:04 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 16:29:00 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_data	*data;
	int		id;
	int		left_chopstick;
	int		right_chopstick;

	data = (t_data *)arg;
	id = data->id;

	set_status_and_put_timestamp(data, id, THINK);

	right_chopstick = id;
	left_chopstick = id + 1;
	if (left_chopstick == data->num_of_philos)
		left_chopstick = 0;

	while (1)
	{
		if (id % 2 == 0)
		{
			get_chopstick(data, id, left_chopstick);
			get_chopstick(data, id, right_chopstick);
		}
		else
		{
			get_chopstick(data, id, right_chopstick);
			get_chopstick(data, id, left_chopstick);
		}
		set_status_and_put_timestamp(data, id, EAT);
		usleep(data->time_to_eat * 1000);
		put_chopstick(data->chopstick, left_chopstick, right_chopstick);

		set_status_and_put_timestamp(data, id, SLEEP);
		usleep(data->time_to_sleep * 1000);

		set_status_and_put_timestamp(data, id, THINK);
	}

	return (NULL);
}
