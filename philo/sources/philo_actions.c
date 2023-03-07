/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:30:23 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/07 17:55:44 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->forkl);
	ft_print(philo, "has taken a fork");
	if (philo->forkr)
		pthread_mutex_lock(philo->forkr);
	else
		return (1);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	philo->meals_eaten++;
	pthread_mutex_lock(&philo->env->changes);
	philo->last_meal = ft_time_now();
	pthread_mutex_unlock(&philo->env->changes);
	ft_sleep(philo->env->time_eat, &philo->env->death);
	pthread_mutex_unlock(philo->forkl);
	pthread_mutex_unlock(philo->forkr);
	return (0);
}

int	ft_philo_dies(t_philo *philo)
{
	if (philo->env->death)
		return (1);
	ft_print(philo, "is dead");
	philo->env->death = 1;
	return (0);
}
