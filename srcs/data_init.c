/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:25:34 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 17:25:42 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_data **data, t_data *arg, int argc, pthread_mutex_t *fork)
{
	int	i;

	*data = (t_data *)malloc(sizeof(t_data) * arg->num_of_philos);
	if (*data == NULL)
		my_error("Malloc failed in data_malloc_and_init.");
	i = 0;
	while (i < arg->num_of_philos)
	{
		(*data)[i].id = i;
		(*data)[i].status = THINK;
		(*data)[i].num_of_philos = arg->num_of_philos;
		(*data)[i].time_to_die = arg->time_to_die;
		(*data)[i].time_to_eat = arg->time_to_eat;
		(*data)[i].time_to_sleep = arg->time_to_sleep;
		if (argc == 6)
			(*data)[i].num_of_times_must_eat = arg->num_of_times_must_eat;
		(*data)[i].fork = fork;
		i++;
	}
}
