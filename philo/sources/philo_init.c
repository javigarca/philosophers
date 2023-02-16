/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:14:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/16 17:32:52 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_mutex(t_table *table)
{
	int	i;

	pthread_mutex_init(&table->env.message, NULL);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->total_philos);
	if (!table->forks)
		ft_exit_error(3);
	i = -1;
	while (++i < table->total_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			ft_exit_error(4);
	}
}

void	ft_set_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->total_philos);
	if (!table->philos)
		ft_exit_error(3);
	i = -1;
	while (++i < table->total_philos)
	{
		table->philos[i].p_id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].dead = 0;
		table->philos[i].env = &table->env;
		ft_set_forks(&table->philos[i], table);
	}
}

void	ft_set_forks(t_philo *philo, t_table *table)
{
	philo->forkl = &table->forks[(philo->p_id - 1)];
	if (philo->p_id == table->total_philos)
		philo->forkr = &table->forks[0];
	else
		philo->forkr = &table->forks[(philo->p_id)];
	if (table->total_philos == 1)
		philo->forkr = NULL;
}

void	ft_set_threads(t_table *table)
{
	int	i;

	i = -1;
	if (pthread_create(&table->aristotle, NULL, &ft_aristotle, &table))
		ft_exit_error(5);
	else
	{
		pthread_mutex_lock(&table->env.message);
		ft_write_str("ARIS BORN", 1);
		pthread_mutex_unlock(&table->env.message);
	}
	while (++i < table->total_philos)
	{
		if (pthread_create(&table->philos[i].t_id, NULL, &ft_philo_thread, \
				&table->philos[i]))
			ft_exit_error(5);
	}
}

void	ft_start_threads(t_table *table)
{
	int	i;

	i = -1;
	if (pthread_join(table->aristotle, NULL))
		ft_exit_error(6);
	else
	{
		pthread_mutex_lock(&table->env.message);
		ft_write_str("ARIS ENGAGED", 1);
		pthread_mutex_unlock(&table->env.message);
	}
	while (++i < table->total_philos)
	{
		if (pthread_join(table->philos[i].t_id, NULL))
			ft_exit_error(6);
	}
}
