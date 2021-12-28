/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:43:39 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 14:40:41 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_left_fork(t_philo *philo, t_hand *hand, int *l_status)
{
	get_fork(philo, hand->left);
	hand->left_status = HOLD;
	*l_status = TAKEN_LEFT;
}

void	take_right_fork(t_philo *philo, t_hand *hand, int *l_status)
{
	if (philo->args->num_of_philos != 1)
	{
		get_fork(philo, hand->right);
		hand->right_status = HOLD;
		*l_status = TAKEN_RIGHT;
	}
	else
		*l_status = DIE;
}

void	do_eat(t_philo *philo, int *l_status)
{
	set_dead_time(philo);
	act_sleep(philo->args->time_to_eat);
	add_eat_count(philo);
	*l_status = SLEEP;
}

void	do_sleep(t_philo *philo, t_hand *hand, int *l_status)
{
	drop_fork(philo, hand->left, hand->right);
	hand->left_status = EMPTY;
	hand->right_status = EMPTY;
	act_sleep(philo->args->time_to_sleep);
	*l_status = THINK;
}
