/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   off_fork_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:08:53 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/24 11:10:38 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static void	fork_array_put(int *fork_array, int num)
{
	int i;

	printf("fork array : ");
	i = 0;
	while (i < num)
	{
		printf("[%d : %d], ", i, fork_array[i]);
		i++;
	}
	printf("\n");
}*/

void	off_fork_flag(t_philo *philo, int left_fork, int right_fork)
{
	pthread_mutex_lock(philo->lock);
	philo->forks->fork_flags[left_fork] = OFF;
	philo->forks->fork_flags[right_fork] = OFF;
//	fork_array_put(philo->fork_array, philo->arg->num_of_philos);
	pthread_mutex_unlock(philo->lock);
}
