/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/16 12:04:48 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	chopstick[PHILOS];
pthread_mutex_t	food_lock;
int				sleep_seconds = 0;

void	my_error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

void	put_timestamp_and_status(int id, int status)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld %u  ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d ", id);
	if (status == THINK)
		printf("is thinking\n");
	else if (status == EAT)
		printf("is eating\n");
	else if (status == SLEEP)
		printf("is sleeping\n");
	else if (status == FORK)
		printf("has taken a fork\n");
}

int	food_on_table(void)
{
	static int	food = FOOD;
	int			myfood;

	pthread_mutex_lock(&food_lock);
	if (food > 0)
		food--;
	myfood = food;
	pthread_mutex_unlock(&food_lock);
	return (myfood);
}

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

void	*philosopher(void *arg)
{
	t_data	*data;
	int		id;
	int		left_chopstick;
	int		right_chopstick;
	int		f;

	data = (t_data *)arg;
	id = data->id;
	put_timestamp_and_status(id, data->status);

	right_chopstick = id;
	left_chopstick = id + 1;
	if (left_chopstick == PHILOS)
		left_chopstick = 0;

	while (1)
	{
		if (id % 2 == 0)
		{
			get_chopstick(id, left_chopstick, "left");
			data->status = TAKEN;
			put_timestamp_and_status(id, data->status);
			get_chopstick(id, right_chopstick, "right");
			data->status = TAKEN;
			put_timestamp_and_status(id, data->status);
		}
		else
		{
			get_chopstick(id, right_chopstick, "right");
			data->status = TAKEN;
			put_timestamp_and_status(id, data->status);
			get_chopstick(id, left_chopstick, "left");
			data->status = TAKEN;
			put_timestamp_and_status(id, data->status);
		}
		data->status = EAT;
		put_timestamp_and_status(id, data->status);
		usleep(data->time_to_eat);
		put_chopstick(left_chopstick, right_chopstick);
		data->status = SLEEP;
		put_timestamp_and_status(id, data->status);
		usleep(data->time_to_sleep);
		data->status = THINK;
		put_timestamp_and_status(id, data->status);
	}

	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	*philo;
	t_data		*data;
	int			num;
	int 		i;

	if (argc < 5 || argc > 6)
		my_error("argc is incorrect.");

	num = atoi(argv[1]);

	philo = (pthread_t *)malloc(sizeof(pthread) * num);

	data = (t_data *)malloc(sizeof(t_data) * num);
	i = 0;
	while (i < num)
	{
		data[i].id = i;
		data[i].status = THINK;
		data[i].num_of_phils = num;
		data[i].time_to_die = atoi(argv[2]);
		data[i].time_to_eat = atoi(argv[3]);
		data[i].time_to_sleep = atoi(argv[4]);
		if (argc == 6)
			data[i].num_of_times_must_eat = argv[5];
	}

	pthread_mutex_init(&food_lock, NULL);

	for (i = 0; i < PHILOS; i++)
		pthread_mutex_init(&chopstick[i], NULL);
	
	for (i = 0; i < PHILOS; i++)
		pthread_create(&philo[i], NULL, philosopher, &data[i]);

	for (i = 0; i < PHILOS; i++)
		pthread_join(philo[i], NULL);

	printf("Philosopher is finish\n");
	return (0);
}
