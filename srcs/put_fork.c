/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:51:27 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 15:58:56 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_fork_flag(t_philo *philo, int fork_position, int *l_fork_flag)
{
	pthread_mutex_lock(philo->lock);
	*l_fork_flag = philo->forks->fork_flags[fork_position];
	pthread_mutex_unlock(philo->lock);
}

void	put_fork(t_philo *philo, t_hand *hand, int id)
{
	int	local_fork_flag;

	get_fork_flag(philo, hand->left, &local_fork_flag);
	if (local_fork_flag == id)
	{
		pthread_mutex_unlock(&philo->forks->forks[hand->left]);
		printf("fork down left hand\n");
	}
	if (hand->left != hand->right)
	{
		get_fork_flag(philo, hand->right, &local_fork_flag);
		if (local_fork_flag == id)
		{
			pthread_mutex_unlock(&philo->forks->forks[hand->right]);
			printf("fork down right hand\n");
		}
	}
}
