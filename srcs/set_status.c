/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:28:13 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 14:16:39 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_status(t_philo *philo, int status)
{
	pthread_mutex_lock(philo->lock);
	philo->status = status;
	pthread_mutex_unlock(philo->lock);
}
