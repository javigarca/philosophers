/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/23 13:21:59 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table		table;

	if (argc < 5 || argc > 6)
		ft_exit_error(1);
	ft_data_validation(argv, argc);
	ft_set_table(argv, argc, &table);
	ft_start_threads(&table);
	printf("FUERA DE START THREADS");
	ft_free_table(&table);
	printf("AQUI ES FIN");
	return (0);
}
