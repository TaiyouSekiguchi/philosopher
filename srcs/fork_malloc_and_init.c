/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_malloc_and_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:14:23 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 17:14:32 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_malloc_and_init(pthread_mutex_t **fork, int num)
{
	int		i;

	*fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (*fork == NULL)
		my_error("Malloc failed in make_fork.");
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&(*fork)[i], NULL);
		i++;
	}
}
