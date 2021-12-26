/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:12:45 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 21:11:08 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	alloc_part(t_lock *lock, int num)
{
	lock->locks = (t_mtx *)malloc(sizeof(t_mtx) * num);
	if (lock->locks == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static int	init_part(t_lock *lock, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&lock->locks[i], NULL) == -1)
		{
			free(lock->locks);
			return (FAILURE);
		}
		i++;
	}
	if (pthread_mutex_init(&lock->common_lock, NULL) == -1)
	{
		free(lock->locks);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	lock_init(t_lock *lock, int num)
{
	if (!alloc_part(lock, num))
		return (FAILURE);
	if (!init_part(lock, num))
		return (FAILURE);
	return (SUCCESS);
}
