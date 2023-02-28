/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:14:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/28 22:11:06 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_set_semaphores(t_table *table)
{
	sem_unlink("sem_message");
	sem_unlink("sem_forks");
	table->env.sem_message = sem_open("sem_message", O_CREAT | O_EXCL, 0644, 1);
	if (!table->env.sem_message)
		ft_exit_error(4);
	table->env.sem_forks = sem_open("sem_forks", \
		O_CREAT | O_EXCL, 0644, table->total_philos);
	if (!table->env.sem_forks)
		ft_exit_error(4);
	return (0);
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
		table->philos[i].philo_id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = table->env.start_time;
		table->philos[i].env = &table->env;
	}
}

int	stop_routines(t_table *table)
{
	int	status;
	int	i;

	i = -1;
	while (++i < table->num_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < table->num_philos)
				kill(table->philos[i].pid, SIGKILL);
			return (0);
		}
	}
	return (0);
}

int	start_routines(t_table *table)
{
	int	i;

	i = -1;
	table->data.start_time = timestamp();
	while (++i < table->num_philos)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid == 0)
			philo_routine(&table->philos[i]);
		else if (table->philos[i].pid < 0)
			return (1);
		usleep(100);
	}
	stop_routines (table);
	return (0);
}
