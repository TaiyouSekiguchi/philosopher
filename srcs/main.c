/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/26 21:09:52 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg		args;
	t_philo		*philos;
	t_monitor	monitor;
	t_fork		forks;
	t_lock		lock;

	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("arg is incorrect.", STDERR_FILENO);
		return (1);
	}
	if (!argv_atoi(&args, argc, argv))
		return (1);
	if (!fork_init(&forks, args.num_of_philos))
		return (1);
	if (!lock_init(&lock, args.num_of_philos))
		return (1);
	if (!philos_init(&philos, &args, &forks, &lock))
		return (1);
	monitor_init(&monitor, philos);
	if (!do_pthread_create(philos, &monitor))
		return (1);
	if (!do_pthread_join(philos, &monitor))
		return (1);
	if (!fork_destroy(&forks, args.num_of_philos))
		return (1);
	if (!lock_destroy(&lock, args.num_of_philos))
		return (1);
	free(philos);

	printf("Philosopher is finish\n");
	return (0);
}
