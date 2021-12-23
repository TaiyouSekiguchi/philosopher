#include "philo.h"

void	set_status(t_philo *philo, int status)
{
	pthread_mutex_lock(philo->lock);
	philo->status = status;
	pthread_mutex_unlock(philo->lock);
}

