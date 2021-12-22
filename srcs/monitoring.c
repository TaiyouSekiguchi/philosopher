/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:32:57 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 23:23:56 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int		time_cmp(int dead_sec, int dead_msec)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (dead_sec < tv.tv_sec
		|| (dead_sec == tv.tv_sec && dead_msec < (tv.tv_usec / 1000)))
		return (1);
	return (0);
}

static int		dead_check(t_monitor *monitor)
{
	int				num;
	int				i;
	int				dead_sec;
	int				dead_msec;
	int				ret;
	int				id;

	num = monitor->philos[0].arg->num_of_philos;
	i = 0;
	while (i < num)
	{

		pthread_mutex_lock(monitor->philos[i].lock);

		dead_sec = monitor->philos[i].dead_sec;
		dead_msec = monitor->philos[i].dead_msec;
		
		pthread_mutex_unlock(monitor->philos[i].lock);
		ret = time_cmp(dead_sec, dead_msec);
		if (ret)
		{
			id = i;
			set_status_and_put_timestamp(&monitor->philos[i], id, DIE);
		}

		if (ret)
			return (1);
		i++;
	}
	return (0);
}

/*static void	dead_exit(t_philo *philos, int id)
{
	int	i;

	set_status_and_put_timestamp(philos, id, DIE);
	i = 0;
	while (i < philos[0].arg->num_of_philos)
	{
		pthread_detach(philos[i].philo);
		philos[i].loop = BREAK;
		i++;
	}
}*/

//static int	eat_count_check(t_monitor *monitor)
//{
	//int				num;
	//int				i;
	//int				tmp;
//
	//num = monitor->philos[0].arg->num_of_philos;
	//i = 0;
	//while (i < num)
	//{
		//pthread_mutex_lock(monitor->philos[0].lock);
		//tmp = monitor->philos[i].eat_count;
		//if (tmp < monitor->philos[i].arg->num_of_times_must_eat)
		//{
			//pthread_mutex_unlock(monitor->philos[0].lock);
			//return (0);
		//}
		//pthread_mutex_unlock(monitor->philos[0].lock);
		//i++;
	//}
	//return (1);
//}

//static void	full_exit(t_philo *philos)
//{
	//int	i;
//
	//i = 0;
	//while (i < philos[0].arg->num_of_philos)
	//{
		//philos[i].loop = BREAK;
		//pthread_detach(philos[i].philo);
		//i++;
	//}
	//printf("full exit\n");
//}

void	*monitoring(void *arg)
{
	t_monitor	*monitor;
	int			ret;
	//int			flag;

	usleep(200);
	monitor = (t_monitor *)arg;
	while (1)
	{
		ret = dead_check(monitor);
		if (ret)
			break ;
		//if (monitor->philos[0].arg->num_of_times_must_eat != NONE)
		//{
			//flag = eat_count_check(monitor);
			//if (flag)
			//{
				//full_exit(monitor->philos);
				//break ;
			//}
		//}
		usleep(100);
	}

	return (NULL);
}
