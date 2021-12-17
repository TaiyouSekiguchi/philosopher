/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status_and_put_timestamp.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:49:26 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/17 16:14:37 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_status(t_data *data, int status, char **msg)
{
	if (status == THINK)
		*msg = "is thinking";
	else if (status == EAT)
	{
		data->eat_count++;
		set_status_time(data);
		*msg = "is eating";
	}
	else if (status == SLEEP)
		*msg = "is sleeping";
	else if (status == TAKEN)
		*msg = "has taken a fork";
	else if (status == DIE)
		*msg = "died";
	else
		*msg = "WHAT!!??";
	data->status = status;
}

void	set_status_and_put_timestamp(t_data *data, int id, int status)
{
	char	*msg;

	msg = NULL;
	set_status(data, status, &msg);
	put_timestamp(id, msg);
}
