/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:31:24 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/27 15:44:14 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	minus_check(char c, int *minus, int *i)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*minus = 1;
		*i += 1;
	}
}

static unsigned int	get_num(const char *str, int minus, int *i)
{
	unsigned int	ret;

	ret = 0;
	while (ft_isdigit(str[*i]))
	{
		if (!ft_int_check(ret, str[*i] - '0', minus))
			return (UINT_MAX);
		ret = ret * 10 + (str[*i] - '0');
		*i += 1;
	}
	return (ret);
}

int	philo_atoi(const char *str)
{
	unsigned int	num;
	int				minus;
	int				i;

	minus = 0;
	i = 0;
	if (str[0] == '\0')
		return (-1);
	while (ft_isspace(str[i]))
		i++;
	minus_check(str[i], &minus, &i);
	if (!ft_isdigit(str[i]))
		return (-1);
	num = get_num(str, minus, &i);
	if (num == UINT_MAX)
		return (-1);
	if (str[i] != '\0')
		return (-1);
	if (minus == 0)
		return (num);
	else
		return (-num);
}
