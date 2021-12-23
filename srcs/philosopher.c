/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:12:04 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 22:56:58 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fork_set(t_fork *fork, int id, t_philo *philo)
{
	fork->left = id + 1;
	fork->right = id;
	if (fork->left == philo->arg->num_of_philos)
		fork->left = 0;
	fork->hold_hand = LEFT;
}

void	*philosopher(void *arg)
{
	t_philo			*philo;
	int				id;
	t_fork			fork;
	int				local_status;
	int				tmp_status;

	philo = (t_philo *)arg;
	id = philo->id;

	//printf("philo[%d] get ready\n", id);
	//set_dead_time(philo);
	set_status(philo, THINK);
	put_timestamp(id, THINK);
	fork_set(&fork, id, philo);

	while (1)
	{
		get_status(philo, &local_status);
		if (local_status == THINK)
		{
			if (philo->group == EVEN)
				usleep(200);
			get_fork(philo, id, fork.left);
			local_status = TAKEN_LEFT;
		}
		else if (local_status == TAKEN_LEFT)
		{
			get_fork(philo, id, fork.right);
			local_status = TAKEN_RIGHT;
		}
		else if (local_status == TAKEN_RIGHT)
		{
			local_status = EAT;
		}
		else if (local_status == EAT)
		{
			set_dead_time(philo);
			usleep(philo->arg->time_to_eat * 1000);
			local_status = SLEEP;
		}
		else if (local_status == SLEEP)
		{
			sleep_and_drop_fork(philo, fork.left, fork.right);
			local_status = THINK;
		}

		get_status(philo, &tmp_status);
		if (tmp_status == DIE || tmp_status == FUNERAL)
			break ;
		else
		{
			set_status(philo, local_status);
			put_timestamp(id, local_status);
		}
	}
	printf("philo[%d] is exit\n", id);
	return (NULL);
}
