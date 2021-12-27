/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:12:04 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 11:13:37 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	hand_set(t_hand *hand, int id, t_philo *philo)
{
	hand->left = id + 1;
	hand->right = id;
	if (hand->left == philo->args->num_of_philos)
		hand->left = 0;
	hand->left_status = EMPTY;
	hand->right_status = EMPTY;
}

void	*philosopher(void *arg)
{
	t_philo		*philo;
	int			id;
	t_hand		hand;
	int			l_status;
	int			tmp_status;

	philo = (t_philo *)arg;
	id = philo->id;

	set_status(philo, THINK);
	put_timestamp(id, THINK);
	hand_set(&hand, id, philo);

	while (1)
	{
		get_status(philo, &l_status);
		if (l_status == THINK)
		{
			if (philo->group == EVEN)
				usleep(200);
			get_fork(philo, hand.left);
			hand.left_status = HOLD;
			l_status = TAKEN_LEFT;
		}
		else if (l_status == TAKEN_LEFT)
		{
			if (philo->args->num_of_philos != 1)
			{
				get_fork(philo, hand.right);
				hand.right_status = HOLD;
				l_status = TAKEN_RIGHT;
			}
			else
				l_status = DIE;
		}
		else if (l_status == TAKEN_RIGHT)
		{
			l_status = EAT;
		}
		else if (l_status == EAT)
		{
			set_dead_time(philo);
			now_eating(philo->args->time_to_eat);
			add_eat_count(philo);
			l_status = SLEEP;
		}
		else if (l_status == SLEEP)
		{
			drop_fork(philo, hand.left, hand.right);
			hand.left_status = EMPTY;
			hand.right_status = EMPTY;
			now_sleeping(philo->args->time_to_sleep);
			l_status = THINK;
		}

		get_status(philo, &tmp_status);
		if (tmp_status == DIE || l_status == DIE || tmp_status == GYM)
		{
			put_fork(philo, &hand);
			break ;
		}
		else
		{
			set_status(philo, l_status);
			put_timestamp(id, l_status);
		}
	}
	printf("philo[%d] is exit\n", id);
	return (NULL);
}
