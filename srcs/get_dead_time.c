#include "philo.h"

void	get_dead_time(t_philo *philo, int *dead_sec, int *dead_msec)
{
	pthread_mutex_lock(philo->lock);
	*dead_sec = philo->dead_sec;
	*dead_msec = philo->dead_msec;
	pthread_mutex_unlock(philo->lock);
}
