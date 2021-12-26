/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:39:30 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 21:06:34 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_destroy(t_lock *lock, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&lock->locks[i]) == -1)
			return (FAILURE);
		i++;
	}
	free(lock->locks);
	if (pthread_mutex_destroy(&lock->common_lock) == -1)
		return (FAILURE);
	return (SUCCESS);
}
