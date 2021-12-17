/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/17 11:42:01 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg				arg;
	pthread_mutex_t		*fork;
	t_data				*data;
	pthread_t			*philos;
	int 				i;

	if (argc < 5 || argc > 6)
		my_error("argc is incorrect.");

	argv_atoi(&arg, argc, argv);
	fork_init(&fork, arg.num_of_philos);
	data_init(&data, &arg, fork);
	philos_init(&philos, arg.num_of_philos);

	i = 0;
	while (i < arg.num_of_philos)
	{
		pthread_create(&philos[i], NULL, philosopher, &data[i]);
		i++;
	}

	i = 0;
	while (i < arg.num_of_philos)
	{
		pthread_join(philos[i], NULL);
		i++;
	}

	printf("Philosopher is finish\n");
	return (0);
}
