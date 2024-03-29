/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:29:49 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/15 19:00:08 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_life(t_philo *philo)
{
	if (!philo->p_id % 2)
		usleep(15000);
	if (pthread_create(&philo->aristotle, NULL, &ft_aristotle, philo))
		ft_exit_error(6);
	while (!philo->env->death)
	{
		if (!ft_philo_eats(philo))
		{
			if ((philo->env->times_m_eat > 0) && \
					(philo->env->times_m_eat == philo->meals_eaten))
				exit(2);
		}
		else
			exit(0);
		ft_print(philo, "is sleeping");
		ft_sleep(philo->env->time_sleep, &philo->env->death);
		ft_print(philo, "is thinking");
	}
	if (pthread_join(philo->aristotle, NULL))
		ft_exit_error(6);
	exit(0);
}

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

void	ft_philo_dies(t_philo *philo)
{
	sem_wait(philo->env->sem_dead);
	ft_print(philo, "died");
	sem_wait(philo->env->sem_message);
	philo->env->death = 1;
	exit(0);
}

void	*ft_aristotle(void *args)
{
	t_philo		*philo;

	philo = (t_philo *) args;
	while (philo->env->death == 0)
	{
		ft_check_death(philo);
		usleep(100);
	}
	return (NULL);
}

void	ft_check_death(t_philo *philo)
{
	long long	hungry;

	hungry = ft_timestamp(philo->last_meal);
	if (hungry > philo->env->time_die)
		ft_philo_dies(philo);
}
