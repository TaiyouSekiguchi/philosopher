/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopstick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:27:13 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/15 23:28:00 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_chopstick(int phil, int c, char *hand)
{
	pthread_mutex_lock(&chopstick[c]);
	printf("Philosopher %d: got %s chopstick %d\n", phil, hand, c);
}

void	put_chopstick(int c1, int c2)
{
	pthread_mutex_unlock(&chopstick[c1]);
	pthread_mutex_unlock(&chopstick[c2]);
}
