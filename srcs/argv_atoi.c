/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:49:23 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 09:32:28 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	return_failure(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (FAILURE);
}

int	argv_atoi(t_arg *args, int argc, char *argv[])
{
	args->num_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (args->num_of_philos <= 0
		|| args->time_to_die < 0
		|| args->time_to_eat < 0
		|| args->time_to_sleep < 0)
		return (return_failure("Argument is incorrect."));
	if (argc == 6)
	{
		args->num_of_times_must_eat = ft_atoi(argv[5]);
		if (args->num_of_times_must_eat < 0)
			return (return_failure("Argument is incorrect."));
	}
	else
		args->num_of_times_must_eat = NONE;
	return (SUCCESS);
}
