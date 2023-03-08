/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:14:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/08 17:43:19 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_set_semaphores(t_table *table)
{
	sem_unlink("sem_dead");
	sem_unlink("sem_message");
	sem_unlink("sem_forks");
	table->env.sem_dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644, 1);
	if (table->env.sem_dead == NULL)
		ft_exit_error(4);
	table->env.sem_message = sem_open("sem_message", O_CREAT | O_EXCL, 0644, 1);
	if (table->env.sem_message == NULL)
		ft_exit_error(4);
	table->env.sem_forks = sem_open("sem_forks", \
		O_CREAT | O_EXCL, 0644, table->total_philos);
	if (table->env.sem_forks == NULL)
		ft_exit_error(4);
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
		table->philos[i].last_meal = table->env.start_time;
		table->philos[i].env = &table->env;
	}
}

void	ft_data_validation(char **data, int argc)
{
	int		i;
	long	chk;

	i = 1;
	while (i < argc)
	{
		chk = ft_myatoi(data[i]);
		if ((chk < 0) || (chk > INT_MAX))
			ft_exit_error(2);
		i++;
	}
}

void	ft_set_table(char **data, int argc, t_table *table)
{
	table->total_philos = ft_myatoi(data[1]);
	table->env.death = 0;
	table->env.time_die = ft_myatoi(data[2]);
	table->env.time_eat = ft_myatoi(data[3]);
	table->env.time_sleep = ft_myatoi(data[4]);
	if (argc == 6)
		table->env.times_m_eat = ft_myatoi(data[5]);
	else
		table->env.times_m_eat = 0;
	ft_set_semaphores(table);
	table->env.start_time = ft_time_now();
	ft_set_philos(table);
}
