/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:05:57 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 18:36:55 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	alloc_part(t_philo **philos, int num)
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * num);
	if (*philos == NULL)
	{
		ft_putendl_fd("malloc failed in philos_init", STDERR);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	do_set(t_philo **philos, t_arg *args, t_mtx *forks, t_mtx *locks)
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
		(*philos)[i].dead_time = 0;
		(*philos)[i].args = args;
		(*philos)[i].forks = forks;
		(*philos)[i].lock = &locks[i];
		i++;
	}
}

int	philos_init(t_philo **philos, t_arg *args, t_mtx *forks, t_mtx *locks)
{
	int	num;

	num = args->num_of_philos;
	if (!alloc_part(philos, num))
		return (FAILURE);
	do_set(philos, args, forks, locks);
	return (SUCCESS);
}
