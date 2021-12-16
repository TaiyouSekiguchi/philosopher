/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 13:27:21 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	pthread_t		*philos;
	pthread_mutex_t	*chopstick;
	t_data			arg;
	t_data			*data;
	int 			i;

	if (argc < 5 || argc > 6)
		my_error("argc is incorrect.");

	arg.num_of_philos = ft_atoi(argv[1]);
	if (arg.num_of_philos < 0)
		my_error("And then there were none...");
	arg.time_to_die = ft_atoi(argv[2]);
	if (arg.time_to_die < 0)
		my_error("time_to_die is negative");
	arg.time_to_eat = ft_atoi(argv[3]);
	if (arg.time_to_eat < 0)
		my_error("time_to_eat is negative");
	arg.time_to_sleep = ft_atoi(argv[4]);
	if (arg.time_to_sleep < 0)
		my_error("time_to_sleep is negative");
	if (argc == 6)
	{
		arg.num_of_times_must_eat = ft_atoi(argv[5]);
		if (arg.num_of_times_must_eat < 0)
			my_error("num_of_times_must_eat is negative");
	}

	philos = (pthread_t *)malloc(sizeof(pthread_t) * arg.num_of_philos);
	if (philos == NULL)
		my_error("Malloc failed in main.");

	data = (t_data *)malloc(sizeof(t_data) * arg.num_of_philos);
	if (data == NULL)
		my_error("Malloc failed in main.");

	chopstick = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg.num_of_philos);
	if (data == NULL)
		my_error("Malloc failed in main.");
	for (i = 0; i < arg.num_of_philos; i++)
		pthread_mutex_init(&chopstick[i], NULL);

	i = 0;
	while (i < arg.num_of_philos)
	{
		data[i].id = i;
		data[i].status = THINK;
		data[i].num_of_philos = arg.num_of_philos;
		data[i].time_to_die = arg.time_to_die;
		data[i].time_to_eat = arg.time_to_eat;
		data[i].time_to_sleep = arg.time_to_sleep;
		if (argc == 6)
			data[i].num_of_times_must_eat = arg.num_of_times_must_eat;
		data[i].chopstick = chopstick;
		i++;
	}

	for (i = 0; i < arg.num_of_philos; i++)
		pthread_create(&philos[i], NULL, philosopher, &data[i]);

	for (i = 0; i <  arg.num_of_philos; i++)
		pthread_join(philos[i], NULL);

	printf("Philosopher is finish\n");
	return (0);
}
