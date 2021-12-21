/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 21:40:00 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg				arg;
	t_philo				*philos;
	t_monitor			monitor;
	pthread_mutex_t		*fork;
	pthread_mutex_t		lock;

	if (argc < 5 || argc > 6)
		my_error("argc is incorrect.");

	argv_atoi(&arg, argc, argv);
	fork_init(&fork, arg.num_of_philos);

	pthread_mutex_init(&lock, NULL);

	philos_init(&philos, &arg, fork, &lock);
	monitor_init(&monitor, philos);
	do_pthread_create(philos, &monitor);
	pthread_join(monitor.monitor, NULL);
	philos_destroy(&philos);
	fork_destroy(&fork, arg.num_of_philos);

	pthread_mutex_destroy(&lock);

	printf("Philosopher is finish\n");
	return (0);
}
