/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_drop_fork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:25:10 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/17 11:33:41 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_and_drop_fork(t_data *data, int left_fork, int right_fork)
{
	set_status_and_put_timestamp(data, data->id, SLEEP);
	pthread_mutex_unlock(&data->fork[left_fork]);
	pthread_mutex_unlock(&data->fork[right_fork]);
	usleep(data->arg->time_to_sleep * 1000);
}
