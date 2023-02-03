/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/03 21:27:03 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	long long	time;
	t_table		table;
	int			i;

	if (argc < 5 || argc >6)
		ft_exit_error(1);
	ft_data_validation(argv, argc);
	ft_set_table(argv, argc, &table);
	ft_write_str("todo bien\n", 1);
	time = ft_time_now();
	printf("Tiempo: %04lld \n", time);
	i = 0;
	while (i < 1000)
	{
		usleep(50);
		i++;
	}
	printf("Tiempo ahora: %04lld \n", (ft_time_now() - time));
	return (0);
}
