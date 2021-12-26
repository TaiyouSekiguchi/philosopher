/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:40:40 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 10:45:19 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_destroy(t_fork *forks, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&forks->forks[i]) == -1)
			return (FAILURE);
		i++;
	}
	free(forks->forks);
	free(forks->fork_flags);
	return (SUCCESS);
}
