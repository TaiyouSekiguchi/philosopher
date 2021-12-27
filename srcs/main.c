/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 12:04:11 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg		args;
	t_philo		*philos;
	t_monitor	monitor;
	t_mtx		*forks;
	t_mtx		*locks;

	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("arg is incorrect.", STDERR);
		return (1);
	}
	if (!argv_atoi(&args, argc, argv)
		|| !mutex_init(&forks, args.num_of_philos)
		|| !mutex_init(&locks, args.num_of_philos)
		|| !philos_init(&philos, &args, forks, locks))
		return (1);
	monitor_init(&monitor, philos);
	if (!do_pthread_create(philos, &monitor)
		|| !do_pthread_join(philos, &monitor)
		|| !mutex_destroy(&forks, args.num_of_philos)
		|| !mutex_destroy(&locks, args.num_of_philos))
		return (1);
	free(philos);
	return (0);
}
