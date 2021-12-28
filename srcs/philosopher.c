/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:12:04 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 08:45:37 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	hand_init(t_hand *hand, int id, t_philo *philo)
{
	hand->left = id + 1;
	hand->right = id;
	if (hand->left == philo->args->num_of_philos)
		hand->left = 0;
	hand->left_status = EMPTY;
	hand->right_status = EMPTY;
}

static void	set_status_and_put_timestamp(t_philo *philo, int status, int id)
{
	set_status(philo, status);
	put_timestamp(id, status);
}

static void	philo_loop(t_philo *philo, t_hand *hand, int id)
{
	int		l_status;
	int		tmp_status;

	while (1)
	{
		get_status(philo, &l_status);
		if (l_status == THINK)
			take_left_fork(philo, hand, &l_status);
		else if (l_status == TAKEN_LEFT)
			take_right_fork(philo, hand, &l_status);
		else if (l_status == TAKEN_RIGHT)
			l_status = EAT;
		else if (l_status == EAT)
			do_eat(philo, &l_status);
		else if (l_status == SLEEP)
			do_sleep(philo, hand, &l_status);
		get_status(philo, &tmp_status);
		if (tmp_status == DIE || l_status == DIE || tmp_status == GYM)
		{
			put_fork(philo, hand);
			break ;
		}
		else
			set_status_and_put_timestamp(philo, l_status, id);
	}
}

void	*philosopher(void *arg)
{
	t_philo		*philo;
	int			id;
	t_hand		hand;

	philo = (t_philo *)arg;
	id = philo->id;
	set_status_and_put_timestamp(philo, THINK, id);
	hand_init(&hand, id, philo);
	if (philo->group == EVEN)
		usleep(200);
	philo_loop(philo, &hand, id);
	return (NULL);
}
