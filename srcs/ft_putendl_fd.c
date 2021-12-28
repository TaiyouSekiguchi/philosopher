/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:14:34 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/28 16:17:28 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	tmp;

	if (s != NULL)
	{
		tmp = write(fd, s, ft_strlen(s));
		tmp = write(fd, "\n", 1);
	}
	(void)tmp;
}
