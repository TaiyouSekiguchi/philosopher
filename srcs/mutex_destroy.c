/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:21:41 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 12:04:38 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_destroy(t_mtx **mutex, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&(*mutex)[i]) != 0)
		{
			ft_putendl_fd("pthread_mutex_destroy failed in mutex_destroy", STDERR);
			return (FAILURE);
		}
		i++;
	}
	free(*mutex);
	return (SUCCESS);
}
