/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pthread_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:22:39 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 14:53:34 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_pthread_create(t_philo *philos, t_monitor *monitor)
{
	int	num;
	int	ret;
	int	i;

	num = philos[0].args->num_of_philos;
	i = 0;
	while (i < num)
	{
		ret = pthread_create(&philos[i].philo, NULL, philosopher, &philos[i]);
		if (ret != 0)
		{
			ft_putendl_fd("pthread_create failed.", STDERR);
			return (FAILURE);
		}
		i++;
	}
	if (pthread_create(&monitor->monitor, NULL, monitoring, monitor) != 0)
	{
		ft_putendl_fd("pthread_create failed.", STDERR);
		return (FAILURE);
	}
	return (SUCCESS);
}
