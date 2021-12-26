/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:19:49 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 12:05:14 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	forks_part(pthread_mutex_t **forks, int num)
{
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (*forks == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static int	fork_flags_part(int **fork_flags, int num)
{
	*fork_flags = (int *)malloc(sizeof(pthread_mutex_t) * num);
	if (*fork_flags == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static int	forks_set(t_fork *forks, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&forks->forks[i], NULL) == -1)
		{
			free(forks->forks);
			return (FAILURE);
		}
		forks->fork_flags[i] = -1;
		i++;
	}
	return (SUCCESS);
}

int	fork_init(t_fork *forks, int num)
{
	if (!forks_part(&forks->forks, num))
		return (FAILURE);
	if (!fork_flags_part(&forks->fork_flags, num))
	{
		free(forks->forks);
		return (FAILURE);
	}
	if (!forks_set(forks, num))
	{
		free(forks->forks);
		return (FAILURE);
	}
	return (SUCCESS);
}
