/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:19:28 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/19 23:01:57 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	table->env.fat = 0;
	table->env.time_die = ft_myatoi(data[2]);
	table->env.time_eat = ft_myatoi(data[3]);
	table->env.time_sleep = ft_myatoi(data[4]);
	if (argc == 6)
		table->env.times_m_eat = ft_myatoi(data[5]);
	else
		table->env.times_m_eat = 0;
	ft_set_mutex(table);
	table->env.start_time = ft_time_now();
	ft_set_philos(table);
	ft_set_threads(table);
}

long	ft_myatoi(const char *str)
{
	int		i;
	int		sign;
	long	atoi;

	i = 0;
	atoi = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if ((!str[i]) || (str[i] == '\0') || (str[i] < 48) || (str[i] > 57))
		ft_exit_error(2);
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
		atoi = atoi * 10 + (str[i++] - 48);
	if (str[i])
		ft_exit_error(2);
	return (atoi * sign);
}

void	ft_free_table(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->env.message);
	i = -1;
	while (++i < table->total_philos)
		pthread_mutex_destroy(&table->forks[i]);
	free(table->forks);
	free(table->philos);
}
