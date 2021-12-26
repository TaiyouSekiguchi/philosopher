/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:12:04 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 17:45:10 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	hand_set(t_hand *hand, int id, t_philo *philo)
{
	hand->left = id + 1;
	hand->right = id;
	if (hand->left == philo->args->num_of_philos)
		hand->left = 0;
}

void	*philosopher(void *arg)
{
	t_philo			*philo;
	int				id;
	t_hand			hand;
	int				local_status;
	int				tmp_status;

	philo = (t_philo *)arg;
	id = philo->id;

	set_status(philo, THINK);
	put_timestamp(id, THINK);
	hand_set(&hand, id, philo);

	while (1)
	{
		get_status(philo, &local_status);
		if (local_status == THINK)
		{
			if (philo->group == EVEN)
				usleep(200);
			get_fork(philo, hand.left);
			on_fork_flag(philo, hand.left);
			local_status = TAKEN_LEFT;
		}
		else if (local_status == TAKEN_LEFT)
		{
			if (philo->args->num_of_philos != 1)
			{
				get_fork(philo, hand.right);
				on_fork_flag(philo, hand.right);
				local_status = TAKEN_RIGHT;
			}
			else
				local_status = DIE;
		}
		else if (local_status == TAKEN_RIGHT)
		{
			local_status = EAT;
		}
		else if (local_status == EAT)
		{
			set_dead_time(philo);
			now_eating(philo->args->time_to_eat);
			add_eat_count(philo);
			local_status = SLEEP;
		}
		else if (local_status == SLEEP)
		{
			drop_fork(philo, hand.left, hand.right);
			off_fork_flag(philo, hand.left, hand.right);
			now_sleeping(philo->args->time_to_sleep);
			local_status = THINK;
		}

		get_status(philo, &tmp_status);
		if (tmp_status == DIE || local_status == DIE || tmp_status == GYM)
		{
			put_fork(philo, &hand, id);
			break ;
		}
		else
		{
			set_status(philo, local_status);
			put_timestamp(id, local_status);
		}
	}
	printf("philo[%d] is exit\n", id);
	return (NULL);
}
