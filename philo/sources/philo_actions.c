/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:30:23 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/20 16:18:39 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_eats(t_philo *philo)
{
 printf("TH = %i\n", philo->env->death);
	if (philo->env->death)
		return (1);
	pthread_mutex_lock(philo->forkl);
	ft_print(philo, "has taken a fork");
	if (philo->forkr)
		pthread_mutex_lock(philo->forkr);
	else
		return (1);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	philo->last_meal = ft_time_now();
	ft_sleep(philo->env->time_eat);
	pthread_mutex_unlock(philo->forkl);
	pthread_mutex_unlock(philo->forkr);
	philo->meals_eaten++;
	return (0);
}

int	ft_philo_sleeps(t_philo *philo, int death)
{
	if (philo && !death)
	{
		ft_print(philo, "is sleeping");
		ft_sleep(philo->env->time_sleep);
		ft_philo_thinks(philo);
	}
	return (0);
}

int	ft_philo_thinks(t_philo *philo)
{
	if (philo)
		ft_print(philo, "is thinking");
	return (0);
}

int	ft_philo_dies(t_philo *philo)
{
	philo->env->death = 1;
	ft_print(philo, "is dead");
	return (0);
}
