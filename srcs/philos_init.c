/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:05:57 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 16:16:57 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	do_malloc(t_philo **philos, int num)
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * num);
	if (*philos == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static void	do_set(t_philo **philos, t_arg *args, t_fork *forks, t_lock *lock)
{
	int	num;
	int	i;

	num = args->num_of_philos;
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
		(*philos)[i].dead.sec = 0;
		(*philos)[i].dead.msec = 0;
		(*philos)[i].args = args;
		(*philos)[i].forks = forks;
		(*philos)[i].lock = lock;
		i++;
	}
}

int	philos_init(t_philo **philos, t_arg *args, t_fork *forks, t_lock *lock)
{
	int	num;

	num = args->num_of_philos;
	if (!do_malloc(philos, num))
		return (FAILURE);
	do_set(philos, args, forks, lock);
	return (SUCCESS);
}
