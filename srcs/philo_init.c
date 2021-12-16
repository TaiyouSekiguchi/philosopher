/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:29:38 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 17:33:08 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(pthread_t **philos, int num)
{
	*philos = (pthread_t *)malloc(sizeof(pthread_t) * num);
	if (*philos == NULL)
		my_error("Malloc failed in philo_init.");
}
