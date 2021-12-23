#include "philo.h"

/*static void	fork_array_put(int *fork_array, int num)
{
	int i;

	printf("fork array : ");
	i = 0;
	while (i < num)
	{
		printf("[%d : %d], ", i, fork_array[i]);
		i++;
	}
	printf("\n");
}*/

void	write_fork_array(t_philo *philo, int fork_position)
{
	pthread_mutex_lock(philo->lock);
	philo->fork_array[fork_position] = philo->id;
	//fork_array_put(philo->fork_array, philo->arg->num_of_philos);
	pthread_mutex_unlock(philo->lock);
}
