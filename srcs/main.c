/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 16:24:37 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg				arg;
	t_philo				*philos;
	t_monitor			monitor;
	pthread_mutex_t		*fork;

	if (argc < 5 || argc > 6)
		my_error("argc is incorrect.");

	argv_atoi(&arg, argc, argv);
	fork_init(&fork, arg.num_of_philos);
	philos_init(&philos, &arg, fork);
	monitor_init(&monitor, philos);
	do_pthread_create(philos, &monitor);
	pthread_join(monitor.monitor, NULL);
	philos_destroy(&philos);
	fork_destroy(&fork, arg.num_of_philos);
	printf("Philosopher is finish\n");
	return (0);
}
