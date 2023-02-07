/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/06 18:41:04 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *args)
{
	t_philo *philo;
	int		d;
	
	philo = (t_philo *) args;
// si el tiempo a morir es 0 o menor de ahora con last meal, muere
	// se pone a comer
	// se pone a dormir
	// se pone a pensar
	d = 0;
	if (!philo->p_id % 2)
		usleep(1500);
	if (philo->env->time_die == 0)
		ft_philo_dies(philo);
	while (!philo->dead)
	{
		printf("PHILO %i\n", philo->p_id);
		ft_print(philo, "is drinking");
		d++;
		if (d == philo->env->times_m_eat)
			ft_philo_dies(philo);
	}
	return(0);
}

void	ft_philo_dies(t_philo *philo)
{
	philo->dead = 1;
	ft_print(philo, "is dead");
}
