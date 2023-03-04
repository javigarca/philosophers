/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/04 22:29:57 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_life(t_philo *philo)
{
	if (philo->env->time_die == 0)
		ft_philo_dies(philo);
	if (pthread_create(&philo->aristotle, NULL, &ft_aristotle, philo))
		ft_exit_error(6);
	while (!philo->env->death)
	{
		if (!ft_philo_eats(philo))
		{
			if ((philo->env->times_m_eat > 0) && \
					(philo->env->times_m_eat == philo->meals_eaten))
				exit(2);
		}
		else
			exit(1);
		ft_print(philo, "is sleeping");
		ft_sleep(philo->env->time_sleep, &philo->env->death);
		ft_print(philo, "is thinking");
	}
	if (pthread_join(philo->aristotle, NULL))
		ft_exit_error(6);
	printf("FUERA: %i\n", philo->p_id);
	exit(0);
}

void	ft_sleep(long long time, int *death)
{
	long long	start;

	start = ft_time_now();
	while (!*death)
	{
		if ((ft_time_now() - start) >= time)
			break ;
		usleep(300);
	}
}

void	*ft_aristotle(void *args)
{
	t_philo		*philo;

	philo = (t_philo *) args;
	while (philo->env->death == 0)
	{
		if (ft_check_death(philo))
			exit (0);
		usleep(10);
	}
	exit(0);
}

int	ft_check_death(t_philo *philo)
{
	long long	hungry;

	hungry = ft_timestamp(philo->last_meal);
	if (hungry > philo->env->time_die)
	{
		ft_philo_dies(philo);
		return (1);
	}
	return (0);
}
