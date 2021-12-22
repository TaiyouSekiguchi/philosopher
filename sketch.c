



void	set_status()
{
	if (status == think)
	{
		if (hand == left)
		{
			hand == right;
		}
		else if (hand == right)
		{
			hand == left;
			status == eat;
		}
	}
	else if (status == eat)
		status == sleep;
	else if (status == sleep)
		status == think;
}

int	philo()
{
	int	status;

	while(status != die)
	{
		pthread_mutex_lock();
		set_status();
		pthread_mutex_unlock();
		
		if (status == think)
		{
			if (hand == left)
				get_fork(left);
			else
				get_fork(right);
		}
		else if (status == eat)
		{
			usleep(time_to_eat * 1000);
		}
		else if (status == sleep)
		{
			usleep(time_to_sleep * 1000);
		}
		else if (status == die)
			break ;
	}
}
