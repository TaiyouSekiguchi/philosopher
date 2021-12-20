/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_drop_fork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:25:10 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 16:55:21 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_and_drop_fork(t_philo *philo, int left_fork, int right_fork)
{
	set_status_and_put_timestamp(philo, philo->id, SLEEP);
	if (pthread_mutex_unlock(&philo->fork[left_fork]) != 0
		|| pthread_mutex_unlock(&philo->fork[right_fork]) != 0)
		printf("pthread_mutex_unlock failed in sleep_and_drop_fork\n");
	usleep(philo->arg->time_to_sleep * 1000);
}
