/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:05:57 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 23:10:20 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	do_malloc(t_philo **philos, int num)
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * num);
	if (*philos == NULL)
		my_error("Malloc failed in philo_data_init.");
}

static void	data_set(t_philo **philos, t_arg *arg, pthread_mutex_t *fork, pthread_mutex_t *lock, int *fork_array)
{
	int	num;
	int	i;

	num = arg->num_of_philos;
	i = 0;
	while (i < num)
	{
		(*philos)[i].philo = 0;
		(*philos)[i].id = i;
		if (i % 2 == 0)
			(*philos)[i].group = EVEN;
		else
			(*philos)[i].group = ODD;
		(*philos)[i].status = THINK;
		(*philos)[i].eat_count = 0;
		(*philos)[i].dead_sec = 0;
		(*philos)[i].dead_msec = 0;
		(*philos)[i].arg = arg;
		(*philos)[i].fork = fork;
		(*philos)[i].fork_array = fork_array;
		(*philos)[i].lock = lock;
		i++;
	}
}

void	philos_init(t_philo **philos, t_arg *arg, pthread_mutex_t *fork, pthread_mutex_t *lock, int *fork_array)
{
	int	num;

	num = arg->num_of_philos;
	do_malloc(philos, num);
	data_set(philos, arg, fork, lock, fork_array);
}
