/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:30:23 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/02 18:48:08 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_philo_eats(t_philo *philo)
{
	if (philo->env->death)
		return (1);
	sem_wait(philo->env->sem_forks);
	ft_print(philo, "has taken a fork");
	sem_wait(philo->env->sem_forks);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	philo->last_meal = ft_time_now();
	ft_sleep(philo->env->time_eat, &philo->env->death);
	philo->meals_eaten++;
	sem_post(philo->env->sem_forks);
	sem_post(philo->env->sem_forks);
	return (0);
}

int	ft_philo_dies(t_philo *philo)
{
	ft_print(philo, "is dead");
	philo->env->death = 1;
	return (0);
}
