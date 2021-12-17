/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:28:00 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 22:28:30 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_init(pthread_t **philos, int num)
{
	*philos = (pthread_t *)malloc(sizeof(pthread_t) * num);
	if (*philos == NULL)
		my_error("Malloc failed in philos_init.");
}
