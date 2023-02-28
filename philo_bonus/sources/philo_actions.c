/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:30:23 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/28 21:54:27 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_philo_eats(t_philo *philo)
{
	if (philo->env->death)
		return (1);
	sem_wait(sem_forks);
	ft_print(philo, "has taken a fork");
	sem_wait(sem_forks);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	philo->last_meal = ft_time_now();
	ft_sleep(philo->env->time_eat, &philo->env->death);
	sem_post(philo->forks);
	sem_post(philo->forks);
	return (0);
}

int	ft_philo_sleeps(t_philo *philo)
{
	if (philo && !(philo->env->death))
	{
		ft_print(philo, "is sleeping");
		ft_sleep(philo->env->time_sleep, &philo->env->death);
		ft_philo_thinks(philo);
	}
	return (0);
}

int	ft_philo_thinks(t_philo *philo)
{
	if (philo && !(philo->env->death))
		ft_print(philo, "is thinking");
	return (0);
}

int	ft_philo_dies(t_philo *philo)
{
	ft_print(philo, "is dead");
	philo->env->death = 1;
	return (0);
}
