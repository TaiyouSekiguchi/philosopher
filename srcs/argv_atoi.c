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

void	argv_atoi(t_arg *arg, int argc, char *argv[])
{
	arg->num_of_philos = ft_atoi(argv[1]);
	if (arg->num_of_philos <= 0)
		my_error("And then there were none...");

	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (arg->time_to_die < 0
		|| arg->time_to_eat < 0
		|| arg->time_to_sleep < 0)
		my_error("Time is negative");

	if (argc == 6)
	{
		arg->num_of_times_must_eat = ft_atoi(argv[5]);
		if (arg->num_of_times_must_eat < 0)
			my_error("Num_of_times_must_eat is negative");
	}
	else
		arg->num_of_times_must_eat = NONE;
}
