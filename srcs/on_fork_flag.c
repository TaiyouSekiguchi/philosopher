/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_fork_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:35:46 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 21:08:30 by tsekiguc         ###   ########.fr       */
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

void	on_fork_flag(t_philo *philo, int fork_position)
{
	pthread_mutex_lock(philo->common_lock);
	philo->forks->fork_flags[fork_position] = philo->id;
	//fork_array_put(philo->fork_array, philo->arg->num_of_philos);
	pthread_mutex_unlock(philo->common_lock);
}
