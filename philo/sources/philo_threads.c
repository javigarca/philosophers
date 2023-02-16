/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/16 13:22:59 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
// DEATHHHHHHH//////////////////
	if (philo->p_id % 2)
		ft_sleep(50);
	if (philo->env->time_die == 0)
		ft_philo_dies(philo);
	while (!philo->dead)
	{
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
