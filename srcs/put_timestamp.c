/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:56:38 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/17 10:58:07 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_timestamp(int id, char *msg)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld%03u %d %s\n", tv.tv_sec, tv.tv_usec / 1000, id, msg);
}
