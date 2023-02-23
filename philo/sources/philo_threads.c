/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/23 13:29:06 by javigarc         ###   ########.fr       */
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
		ft_sleep(50);
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
				ft_philo_dies(&academia->philos[i]);
		//		pthread_mutex_lock(&academia->env.message);
	//			ft_terminate(academia);
		//		pthread_mutex_unlock(&academia->env.message);
	//			pthread_cancel(pthread_self());
				printf("salida de deaths\n");
				return (NULL);
			}
		}
		if (academia->env.times_m_eat && \
				(academia->env.fat == academia->total_philos))
		{
			ft_write_str("All philos are full and happy\n", 1);
			academia->env.death = 1;
		//	pthread_mutex_lock(&academia->env.message);
	//		ft_terminate(academia);
	//		pthread_exit(NULL);
			printf("salida de fulls\n");
		//	pthread_mutex_unlock(&academia->env.message);
			return (NULL);
		}
		ft_sleep(10);
	}
	return (NULL);
}

void	ft_terminate(t_table *table)
{
	int	i;

	i = 0;
	printf("tErMiNaTe\n");
	while (i < table->total_philos)
	{
//		pthread_exit(table->philos[i].t_id);
		if (!pthread_cancel(table->philos[i].t_id))
			printf("Hilo cerrado: %i\n", i);
		i++;
	}
	printf("Sali del hilo?\n");
//	pthread_exit(table->aristotle);
//	printf("ARIS cerrado\n");
}
