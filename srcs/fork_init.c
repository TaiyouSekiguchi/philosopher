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

void	fork_init(pthread_mutex_t **fork, int num)
{
	int		i;

	*fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (*fork == NULL)
		my_error("Malloc failed in fork_init.");
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&(*fork)[i], NULL) == -1)
		{
			free(*fork);
			my_error("pthread_mutex_init failed in fork_init");
		}
		i++;
	}
}
