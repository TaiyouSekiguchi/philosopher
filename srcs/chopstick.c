/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopstick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:10:45 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 13:19:54 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_chopstick(t_data *data, int id, int cs_num)
{
	pthread_mutex_lock(&data->chopstick[cs_num]);
	set_status_and_put_timestamp(data, id, TAKEN);
}

void	put_chopstick(pthread_mutex_t *chopstick, int left_cs, int right_cs)
{
	pthread_mutex_unlock(&chopstick[left_cs]);
	pthread_mutex_unlock(&chopstick[right_cs]);
}
