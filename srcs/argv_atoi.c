/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:49:23 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/20 11:52:31 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argv_atoi(t_arg *args, int argc, char *argv[])
{
	args->num_of_philos = ft_atoi(argv[1]);
	if (args->num_of_philos <= 0)
		return (FAILURE);

	printf("a 0\n");
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (args->time_to_die < 0
		|| args->time_to_eat < 0
		|| args->time_to_sleep < 0)
		return (FAILURE);
	printf("a 1\n");

	if (argc == 6)
	{
		args->num_of_times_must_eat = ft_atoi(argv[5]);
		if (args->num_of_times_must_eat < 0)
			return (FAILURE);
	}
	else
		args->num_of_times_must_eat = NONE;
	
	printf("a 2\n");
	return (SUCCESS);
}
