/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pthread_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:27:55 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 14:27:57 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_pthread_join(t_philo *philos, t_monitor *monitor)
{
	int	num;
	int	i;

	num = philos[0].args->num_of_philos;
	i = 0;
	while (i < num)
	{
		if (pthread_join(philos[i].philo, NULL) != 0)
		{
			ft_putendl_fd("pthread_join failed int do_pthread_join.", STDERR);
			return (FAILURE);
		}
		i++;
	}
	if (pthread_join(monitor->monitor, NULL) != 0)
	{
		ft_putendl_fd("pthread_join failed int do_pthread_join.", STDERR);
		return (FAILURE);
	}
	return (SUCCESS);
}
