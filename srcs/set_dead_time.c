/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dead_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:49:11 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 18:49:03 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dead_time(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	philo->dead_time = get_time() + philo->args->time_to_die;
	pthread_mutex_unlock(philo->lock);
}
