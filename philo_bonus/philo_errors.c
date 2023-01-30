/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:23:31 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/17 10:59:12 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	ft_issign(int c)
{
	if ((c == 43) || (c == 45))
		return (1);
	return (0);
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

void	ft_pr_action(int op)
{
	if (op == 1)
		write(1, "sa\n", 3);
	if (op == 2)
		write(1, "sb\n", 3);
	if (op == 3)
		write(1, "ss\n", 3);
	if (op == 4)
		write(1, "pa\n", 3);
	if (op == 5)
		write(1, "pb\n", 3);
	if (op == 6)
		write(1, "ra\n", 3);
	if (op == 7)
		write(1, "rb\n", 3);
	if (op == 8)
		write(1, "rr\n", 3);
	if (op == 9)
		write(1, "rra\n", 4);
	if (op == 10)
		write(1, "rrb\n", 4);
	if (op == 11)
		write(1, "rrr\n", 4);
}
