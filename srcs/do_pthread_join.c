/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pthread_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:27:55 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 19:36:02 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_pthread_join(t_philo *philos, t_monitor *monitor)
{
	int	num;
	int	i;

	num = philos[0].args->num_of_philos;
	i = 0;
	while (i < num)
	{
		pthread_join(philos[i].philo, NULL);
		i++;
	}
	pthread_join(monitor->monitor, NULL);
}
