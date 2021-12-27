/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:07:40 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 10:41:46 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_fork(t_philo *philo, int left_fork, int right_fork)
{
	pthread_mutex_unlock(&philo->forks[left_fork]);
	pthread_mutex_unlock(&philo->forks[right_fork]);
}
