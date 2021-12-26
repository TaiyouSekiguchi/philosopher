/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pthread_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:22:39 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 16:22:48 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_pthread_create(t_philo *philos, t_monitor *monitor)
{
	int	num;
	int	i;

	num = philos[0].args->num_of_philos;
	i = 0;
	while (i < num)
	{
		if (pthread_create(&philos[i].philo, NULL, philosopher, &philos[i]) == -1)
			return (FAILURE);
		i++;
	}

	if (pthread_create(&monitor->monitor, NULL, monitoring, monitor) == -1)
		return (FAILURE);
	return (SUCCESS);
}
