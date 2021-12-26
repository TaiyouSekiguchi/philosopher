#include "philo.h"

int	do_pthread_join(t_philo *philos, t_monitor *monitor)
{
	int	num;
	int	i;

	num = philos[0].args->num_of_philos;
	i = 0;
	while (i < num)
	{
		if (pthread_join(philos[i].philo, NULL) == -1)
			return (FAILURE);
		i++;
	}
	if (pthread_join(monitor->monitor, NULL) == -1)
		return (FAILURE);
	return (SUCCESS);
}
