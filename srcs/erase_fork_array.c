#include "philo.h"

void	erase_fork_array(t_philo *philo, int left_fork, int right_fork)
{
	pthread_mutex_lock(philo->lock);
	philo->fork_array[left_fork] = 0;
	philo->fork_array[right_fork] = 0;
	pthread_mutex_unlock(philo->lock);
}
