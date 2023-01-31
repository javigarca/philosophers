/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:32:13 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/31 19:46:42 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_data_load(char **data, int argc, t_env table)
{
	printf("HOLA %i", argc);
	table.total_philos = ft_myatoi(data[1]);
	table.philos = malloc(sizeof(t_philo) * table.total_philos);

}
