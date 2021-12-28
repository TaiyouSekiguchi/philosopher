/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 17:58:59 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	my_init(t_arg *args, t_mtx **forks, t_mtx **locks, t_philo **philos)
{
	*forks = NULL;
	*locks = NULL;
	*philos = NULL;
	if (!mutex_init(forks, args->num_of_philos)
		|| !mutex_init(locks, args->num_of_philos)
		|| !philos_init(philos, args, *forks, *locks))
	{
		if (*forks != NULL)
			free(*forks);
		if (*locks != NULL)
			free(*locks);
		if (*philos != NULL)
			free(*philos);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_arg		args;
	t_philo		*philos;
	t_monitor	monitor;
	t_mtx		*forks;
	t_mtx		*locks;

	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Error: invalid arguments", STDERR);
		return (1);
	}
	if (!argv_atoi(&args, argc, argv)
		|| !my_init(&args, &forks, &locks, &philos))
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
