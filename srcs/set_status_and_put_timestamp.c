/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status_and_put_timestamp.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:49:26 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 16:19:49 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_status_and_put_timestamp(t_data *data, int id, int status)
{
	struct timeval	tv;
	char			*msg;

	msg = NULL;
	data->status = status;
	if (status == THINK)
		msg = "is thinking";
	else if (status == EAT)
		msg = "is eating";
	else if (status == SLEEP)
		msg = "is sleeping";
	else if (status == TAKEN)
		msg = "has taken a fork";
	else
		msg = "WHAT!!??";

	gettimeofday(&tv, NULL);
	printf("%ld%03u %d %s\n", tv.tv_sec, tv.tv_usec / 1000, id, msg);
}
