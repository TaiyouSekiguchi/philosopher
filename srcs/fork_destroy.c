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

void	fork_destroy(pthread_mutex_t **fork, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&(*fork)[i]);
		i++;
	}
	free(*fork);
}
