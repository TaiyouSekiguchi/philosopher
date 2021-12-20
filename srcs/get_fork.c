/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:09:38 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 15:49:33 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo, int id, int fork_id)
{
	pthread_mutex_lock(&philo->fork[fork_id]);
	set_status_and_put_timestamp(philo, id, TAKEN);
}
