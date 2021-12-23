#include "philo.h"

void	drop_fork(t_philo *philo, int left_fork, int right_fork)
{
	if (pthread_mutex_unlock(&philo->fork[left_fork]) != 0
		|| pthread_mutex_unlock(&philo->fork[right_fork]) != 0)
		printf("pthread_mutex_unlock failed in sleep_and_drop_fork\n");
}
