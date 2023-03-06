/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:30:23 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/04 22:04:05 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_start_process(t_table *table)
{
	int	i;

	table->env.start_time = ft_time_now();
	printf("tiempo start antes: %lld\n", table->env.start_time);
	i = -1;
//	printf("AHORA EMPIEZAS: %lld\n", ft_timestamp(table->env.start_time));
	while (++i < table->total_philos)
	{
	//	printf("tiempo start philos: %lld\n", table->philos[i].env->start_time);
	printf("AHORA EMPIEZAS: %lld\n", ft_timestamp(table->env.start_time));
		table->philos[i].f_id = fork();
//	printf("AHORA EMPIEZAS: %lld\n", ft_timestamp(table->env.start_time));
		if (table->philos[i].f_id == 0)
			ft_philo_life(&table->philos[i]);
		else if (table->philos[i].f_id < 0)
			ft_exit_error(5);
	printf("AHORA acabas: %lld\n", ft_timestamp(table->env.start_time));
		usleep(100);
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
		if (status != 2)
		{
			i = -1;
			while (++i < table->total_philos)
				kill(table->philos[i].f_id, SIGKILL);
		}
	}
}