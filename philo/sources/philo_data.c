/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:19:28 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/30 18:01:26 by javigarc         ###   ########.fr       */
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
			ft_exit_error();
		i++;
	}
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
		ft_exit_error();
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
		atoi = atoi * 10 + (str[i++] - 48);
	if (str[i])
		ft_exit_error();
	return (atoi * sign);
}
