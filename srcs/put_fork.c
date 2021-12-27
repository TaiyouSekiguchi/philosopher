/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:51:27 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 10:44:57 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_fork(t_philo *philo, t_hand *hand)
{
	if (hand->left_status == HOLD)
		pthread_mutex_unlock(&philo->forks[hand->left]);
	if (hand->left != hand->right)
	{
		if (hand->right_status == HOLD)
			pthread_mutex_unlock(&philo->forks[hand->right]);
	}
}
