/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/06 21:55:11 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table		table;

	if (argc < 5 || argc > 6)
		ft_exit_error(1);
	ft_data_validation(argv, argc);
	ft_set_table(argv, argc, &table);
	ft_start_process(&table);
	ft_free_table(&table);
	return (0);
}
