/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/20 16:32:51 by javi             ###   ########.fr       */
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
		usleep(10000);
	if (philo->env->time_die == 0)
		ft_philo_dies(philo);
	while (philo->env->death == 0)
	{
		if (!ft_philo_eats(philo))
		{
			if (philo->env->times_m_eat == philo->meals_eaten)
				philo->env->fat++;
		}
		else
			return (NULL);
		ft_philo_sleeps(philo, philo->env->death);
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
				//ft_write_str("Aristotle sees you fasting. DIE!!\n", 1);
				ft_philo_dies(&academia->philos[i]);
				printf("DEATH = %i\n", academia->env.death);
					return (NULL);
			}
		}
		if (academia->env.times_m_eat && (academia->env.fat == academia->total_philos))
		{
			//ft_write_str("All philos are full and happy\n", 1);
			ft_print(&academia->philos[0], "FULL && HAPPY\n");
			academia->env.death = 1;
			return (NULL);
		}
		ft_sleep(10);
	}
	return (NULL);
}
