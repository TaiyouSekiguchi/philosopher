/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:16:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/15 23:42:16 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	chopstick[PHILOS];
pthread_t		philo[PHILOS];
pthread_mutex_t	food_lock;
int				sleep_seconds = 0;

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

void	*philosopher(void *num)
{
	int	id;
	int	left_chopstick;
	int	right_chopstick;
	int	f;

	id = *((int *)num);
	printf("philosopher %d is done thinking and nou ready to eat\n", id);
	right_chopstick = id;
	left_chopstick = id + 1;

	if (left_chopstick == PHILOS)
		left_chopstick = 0;

	f = food_on_table();
	while (f)
	{
		if (id == 1)
			sleep(sleep_seconds);

		get_chopstick(id, right_chopstick, "right");
		get_chopstick(id, left_chopstick, "left");

		printf("Philosopher %d: eating.\n", id);
		usleep(DELAY * (FOOD -f + 1));
		put_chopstick(left_chopstick, right_chopstick);
		f = food_on_table();
	}

	printf("Philosopher %d: is done eating.\n", id);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int i;

	if (argc == 2)
		sleep_seconds = atoi(argv[1]);

	pthread_mutex_init(&food_lock, NULL);
	for (i = 0; i < PHILOS; i++)
		pthread_mutex_init(&chopstick[i], NULL);
	for (i = 0; i < PHILOS; i++)
		pthread_create(&philo[i], NULL, philosopher, &i);
	for (i = 0; i < PHILOS; i++)
		pthread_join(philo[i], NULL);
	printf("Philosopher is finish\n");
	return (0);
}
