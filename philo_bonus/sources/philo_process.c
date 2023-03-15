/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:30:23 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/15 18:48:28 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_start_process(t_table *table)
{
	int	i;

	table->env.start_time = ft_time_now();
	i = -1;
	while (++i < table->total_philos)
	{
		table->philos[i].f_id = fork();
		if (table->philos[i].f_id == 0)
			ft_philo_life(&table->philos[i]);
		else if (table->philos[i].f_id < 0)
			ft_exit_error(5);
	}
	ft_stop_process(table);
}

void	ft_stop_process(t_table *table)
{
	int	status;
	int	i;

	i = -1;
	while (++i < table->total_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 512)
		{
			i = -1;
			while (++i < table->total_philos)
				kill(table->philos[i].f_id, SIGKILL);
		}
	}
}
