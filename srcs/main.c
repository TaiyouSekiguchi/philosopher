/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 11:23:22 by tsekiguc         ###   ########.fr       */
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
		ft_putendl_fd("arg is incorrect.", STDERR_FILENO);
		return (1);
	}
	if (!argv_atoi(&args, argc, argv))
		return (1);
	if (!mutex_init(&forks, args.num_of_philos))
		return (1);
	if (!mutex_init(&locks, args.num_of_philos))
		return (1);
	if (!philos_init(&philos, &args, forks, locks))
		return (1);
	monitor_init(&monitor, philos);
	if (!do_pthread_create(philos, &monitor))
		return (1);
	if (!do_pthread_join(philos, &monitor))
		return (1);
	if (!mutex_destroy(&forks, args.num_of_philos))
		return (1);
	if (!mutex_destroy(&locks, args.num_of_philos))
		return (1);
	free(philos);
	return (0);
}
