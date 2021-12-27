/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:43:05 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 15:36:47 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_int_check(unsigned int input, unsigned int add, int minus)
{
	unsigned int	input_limit;
	unsigned int	add_limit;
	unsigned int	tmp;

	tmp = INT_MAX;
	if (minus == 1)
		tmp++;
	input_limit = tmp / 10;
	add_limit = tmp % 10;
	if (input > input_limit || (input == input_limit && add > add_limit))
		return (0);
	return (1);
}
