/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:25:34 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/17 11:38:47 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_data **data, t_arg *arg, pthread_mutex_t *fork)
{
	int	i;

	*data = (t_data *)malloc(sizeof(t_data) * arg->num_of_philos);
	if (*data == NULL)
		my_error("Malloc failed in data_init.");
	i = 0;
	while (i < arg->num_of_philos)
	{
		(*data)[i].id = i;
		if (i % 2 == 0)
			(*data)[i].group = EVEN;
		else
			(*data)[i].group = ODD;
		(*data)[i].status = THINK;
		(*data)[i].status_sec = 0;
		(*data)[i].status_msec = 0;
		(*data)[i].arg = arg;
		(*data)[i].fork = fork;
		i++;
	}
}
