/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_eat_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:17:17 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 17:19:15 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_eat_count(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	philo->eat_count++;
	pthread_mutex_unlock(philo->lock);
}
