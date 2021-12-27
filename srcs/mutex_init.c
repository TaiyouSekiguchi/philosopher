/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:56:10 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 09:57:59 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	alloc_part(t_mtx **mutex, int num)
{
	*mutex = (t_mtx *)malloc(sizeof(t_mtx) * num);
	if (*mutex == NULL)
	{
		ft_putendl_fd("malloc failed in mutex_init", STDERR_FILENO);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	init_part(t_mtx **mutex, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&(*mutex)[i], NULL) == -1)
		{
			ft_putendl_fd("pthread_mutex_init failed in mutex_init", STDERR_FILENO);
			free(*mutex);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	mutex_init(t_mtx **mutex, int num)
{
	if (!alloc_part(mutex, num))
		return (FAILURE);
	if (!init_part(mutex, num))
		return (FAILURE);
	return (SUCCESS);
}
