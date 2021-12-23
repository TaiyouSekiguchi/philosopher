#include "philo.h"

void	get_status(t_philo *philo, int *status)
{
	pthread_mutex_lock(philo->lock);
	*status = philo->status;
	pthread_mutex_unlock(philo->lock);
}
