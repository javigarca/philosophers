/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/19 23:07:36 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	if (philo->p_id % 2)
		ft_sleep(100);
	if (philo->env->time_die == 0)
		ft_philo_dies(philo);
	while (!philo->env->death)
	{
		if (!ft_philo_eats(philo))
		{
			if (philo->env->times_m_eat == philo->meals_eaten)
				philo->env->fat++;
		}
		ft_philo_sleeps(philo);
		ft_philo_thinks(philo);
	}
	return (NULL);
}

void	ft_sleep(long long time)
{
	long long	start;

	start = ft_time_now();
	while ((ft_time_now() - start) <= time)
		usleep(50);
}

void	*ft_aristotle(void *args)
{
	t_table		*academia;
	int			i;
	long long	hungry;

	academia = (t_table *) args;
	while (academia->env.death == 0)
	{
		i = -1;
		while (++i < academia->total_philos)
		{
			hungry = ft_timestamp(academia->philos[i].last_meal);
			if (hungry > academia->env.time_die)
			{
				printf("Hun: %lli\n", hungry);
				ft_write_str("Aristotle sees you fasting. DIE!!\n", 1);
				ft_philo_dies(&academia->philos[i]);
			//		return (NULL);;
			}
		}
		if (academia->env.times_m_eat && (academia->env.fat == academia->total_philos))
		{
			ft_write_str("All philos are full and happy", 1);
			academia->env.death = 1;
		}
		ft_sleep(100);
	}

	return (NULL);
}
