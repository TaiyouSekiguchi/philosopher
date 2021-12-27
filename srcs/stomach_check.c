/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stomach_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:58:54 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 11:03:26 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_eat_count(t_philo *philo, int *l_eat_count)
{
	pthread_mutex_lock(philo->lock);
	*l_eat_count = philo->eat_count;
	pthread_mutex_unlock(philo->lock);
}

static void	all_status_gym(t_monitor *monitor, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		set_status(&monitor->philos[i], GYM);
		i++;
	}
}

int	stomack_check(t_monitor *monitor, int num)
{
	int	l_eat_count;
	int	must_eat;
	int	i;

	must_eat = monitor->philos[0].args->num_of_times_must_eat;
	i = 0;
	while (i < num)
	{
		get_eat_count(&monitor->philos[i], &l_eat_count);
		if (must_eat > l_eat_count)
			return (HUNGRY);
		i++;
	}
	all_status_gym(monitor, num);
	return (FULL);
}
