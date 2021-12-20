/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:12:04 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 17:08:25 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_set(int *left_fork, int *right_fork, int id, t_philo *philo)
{
	*left_fork = id + 1;
	*right_fork = id;
	if (*left_fork == philo->arg->num_of_philos)
		*left_fork = 0;
}

void	*philosopher(void *arg)
{
	t_philo			*philo;
	int				id;
	int				left_fork;
	int				right_fork;

	philo = (t_philo *)arg;
	id = philo->id;
	set_status_time(philo);
	set_status_and_put_timestamp(philo, id, THINK);

	fork_set(&left_fork, &right_fork, id, philo);

	while (philo->loop == GO)
	{
		if (philo->group == EVEN)
			usleep(200);
		get_fork(philo, id, left_fork);
		get_fork(philo, id, right_fork);

		set_status_and_put_timestamp(philo, id, EAT);
		usleep(philo->arg->time_to_eat * 1000);

		sleep_and_drop_fork(philo, left_fork, right_fork);

		set_status_and_put_timestamp(philo, id, THINK);
	}

	return (NULL);
}
