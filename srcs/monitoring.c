/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:32:57 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 16:02:06 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_dead_time(t_philo *philo, int *dead_sec, int *dead_msec)
{
	int		tmp;
	int		sec;
	int		msec;

	tmp = philo->status_msec + philo->arg->time_to_die;
	sec = tmp / 1000;
	msec = tmp % 1000;

	*dead_sec = philo->status_sec + sec;
	*dead_msec = msec;
}

static int		dead_check(t_monitor *monitor)
{
	struct timeval	tv;
	int				i;
	int				num;
	int				dead_sec;
	int				dead_msec;

	num = monitor->philos[0].arg->num_of_philos;
	i = 0;
	while (i < num)
	{
		set_dead_time(&monitor->philos[i], &dead_sec, &dead_msec);
		gettimeofday(&tv, NULL);
		if (dead_sec < tv.tv_sec
			|| (dead_sec == tv.tv_sec && dead_msec < (tv.tv_usec / 1000)))
			return (i);
		i++;
	}
	return (-1);
}

/*static int	must_eat_check(t_data *data)
{
	int		i;
	int		num;
	int		must_eat_count;

	num = data[0].arg->num_of_philos;
	must_eat_count = data[0].arg->num_of_times_must_eat;
	i = 0;
	while (i < num)
	{
		if (data[i].eat_count < must_eat_count)
			return (0);
		i++;
	}
	return (1);
}*/

static void	dead_exit(t_philo *philos, int id)
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
}

/*static void full_exit(void)
{
	exit(0);
}*/

void	*monitoring(void *arg)
{
	t_monitor	*monitor;
	int		ret;
	//int		flag;
	//int		must_eat_count;

	monitor = (t_monitor *)arg;
	//must_eat_count = data->arg->num_of_times_must_eat;
	while (1)
	{
		ret = dead_check(monitor);
		//flag = must_eat_check(monitor);
		if (ret >= 0)
		{
			dead_exit(monitor->philos, ret);
			break ;
		}
		//if (must_eat_count >= 0 && flag)
			//full_exit();
		usleep(100);
	}

	return (NULL);
}
