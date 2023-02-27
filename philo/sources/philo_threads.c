/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/27 19:56:14 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	pthread_mutex_lock(&philo->env->genesis);
	pthread_mutex_unlock(&philo->env->genesis);
	if (!(philo->p_id % 2))
		usleep(1000);
	if (philo->env->time_die == 0)
		ft_philo_dies(philo);
	while (!philo->env->death)
	{
		if (!ft_philo_eats(philo))
		{
			if (philo->env->times_m_eat == philo->meals_eaten)
				philo->env->fat++;
		}
		else
			return (NULL);
		ft_philo_sleeps(philo);
		usleep(50);
	}
	return (NULL);
}

void	ft_sleep(long long time, int *death)
{
	long long	start;

	start = ft_time_now();
	while (!*death)
	{
		if ((ft_time_now() - start) >= time)
			break ;
		usleep(50);
	}
}

void	*ft_aristotle(void *args)
{
	t_table		*academia;

	academia = (t_table *) args;
	while (academia->env.death == 0)
	{
		if (ft_check_death(academia))
			return (NULL);
		if (academia->env.times_m_eat && \
				(academia->env.fat == academia->total_philos))
		{
			academia->env.death = 1;
			return (NULL);
		}
		usleep(10);
	}
	return (NULL);
}

int	ft_check_death(t_table *academia)
{
	int			i;
	long long	hungry;

	i = -1;
	while (++i < academia->total_philos)
	{
		hungry = ft_timestamp(academia->philos[i].last_meal);
		if (hungry > academia->env.time_die)
		{
			ft_philo_dies(&academia->philos[i]);
			return (1);
		}
	}
	return (0);
}
