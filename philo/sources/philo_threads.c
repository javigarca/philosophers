/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/16 17:32:55 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	if (philo->p_id % 2)
		ft_sleep(50);
	while (!philo->dead)
	{
		if (philo->env->time_die == 0)
			ft_philo_dies(philo);
		ft_philo_eats(philo);
		if (philo->env->times_m_eat == philo->meals_eaten)
		{
			ft_print(philo, "is full");
			break ;
		}
		ft_philo_sleeps(philo);
		ft_philo_thinks(philo);
	}
	return (0);
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
	t_table	*academia;
	int		i;
	int		z;

	academia = (t_table *) args;
	i = 0;
	z = 0;

	while (z < INT_MAX)
	{
		while (i < academia->total_philos)
		{
			if (academia->philos[i].dead)
			{
				ft_write_str("Aristotles sees you. DIE!!", 1);
				ft_stop_threads(academia);
			}
		}
		z++;
	}
	return (0);
}

void	ft_terminate(t_table *table)
{
	int	i;

	i = 0;
//	while (i < table->total_philos)i
//		pthread_exit(// stop all threads de table
//		MUERTE POR MUTEX
	ft_free_table(table);
	exit(0);
}
