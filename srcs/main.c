/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 17:35:06 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	pthread_t		*philos;
	pthread_mutex_t	*fork;
	t_data			arg;
	t_data			*data;
	int 			i;

	if (argc < 5 || argc > 6)
		my_error("argc is incorrect.");
	argv_atoi(&arg, argc, argv);
	fork_malloc_and_init(&fork, arg.num_of_philos);
	data_init(&data, &arg, argc, fork);

	philo_init(&philos, arg.num_of_philos);

	for (i = 0; i < arg.num_of_philos; i++)
		pthread_create(&philos[i], NULL, philosopher, &data[i]);
	for (i = 0; i <  arg.num_of_philos; i++)
		pthread_join(philos[i], NULL);

	printf("Philosopher is finish\n");
	return (0);
}
