#include "philo.h"

void	write_fork_array(t_philo *philo, int fork_position)
{
	pthread_mutex_lock(philo->lock);
	philo->fork_array[fork_position] = 1;
	pthread_mutex_unlock(philo->lock);
}
