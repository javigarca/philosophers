/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/31 19:47:34 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	long long	time;
	t_env		table;

	if (argc < 5 || argc >6)
		ft_exit_error(1);
	ft_data_validation(argv, argc);
	ft_data_load(argv, argc, table);
	ft_write_str("todo bien\n", 1);
	time = ft_time_now();
	printf("Tiempo: %04lld \n", time);
	usleep(10000);
	printf("Tiempo ahora: %04lld \n", (ft_time_now() - time));
	return (0);
}
