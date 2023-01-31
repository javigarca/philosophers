/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:23:31 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/31 12:38:56 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit_error(int err)
{
	if (err == 1)
		ft_write_str("Usage ./philo nbr_philos time_die time_eat time_sleep (optional) times_must_eat.\n", 2);
	if (err == 2)
		ft_write_str("Invalid arguments.\n", 2);
	if (!err)
		ft_write_str("Error.\n", 2);
	exit(0);
}

int	ft_write_str(char *str, int channel)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(channel, str, len);
	return (len);
}

long long	ft_time_now(void)
{
	struct timeval	time;
	long long		now;

	gettimeofday(&time, NULL);
	now =(time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (now);
}
