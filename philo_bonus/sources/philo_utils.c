/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:14:41 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/14 21:32:08 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_exit_error(int err)
{
	if (err == 1)
		ft_write_str("Usage ./philo_bonus nbr_philos time_die time_eat time_sleep \
(optional) times_must_eat.\n", 2);
	if (err == 2)
		ft_write_str("Invalid arguments.\n", 2);
	if (err == 3)
		ft_write_str("Memory error.\n", 2);
	if (err == 4)
		ft_write_str("Semaphore error.\n", 2);
	if (err == 5)
		ft_write_str("Process error.\n", 2);
	if (err == 6)
		ft_write_str("Thread error.\n", 2);
	if (!err)
		ft_write_str("Error.\n", 2);
	exit(1);
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
	now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (now);
}

long long	ft_timestamp(long long time)
{
	long long		now;

	now = ft_time_now();
	return (now - time);
}

void	ft_print(t_philo *philo, char *msg)
{
	long long	now;

	sem_wait(philo->env->sem_message);
	now = ft_timestamp(philo->env->start_time);
	if (!philo->env->death)
		printf("%.04lld Philosopher %d %s\n", now, philo->p_id, msg);
	sem_post(philo->env->sem_message);
}
