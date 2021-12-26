/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:07:40 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/24 11:07:52 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_fork(t_philo *philo, int left_fork, int right_fork)
{
	if (pthread_mutex_unlock(&philo->forks->forks[left_fork]) != 0
		|| pthread_mutex_unlock(&philo->forks->forks[right_fork]) != 0)
		printf("pthread_mutex_unlock failed in sleep_and_drop_fork\n");
}
