/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:49:11 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/17 11:00:28 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_status_time(t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	data->status_sec = tv.tv_sec;
	data->status_msec = tv.tv_usec / 1000;
}
