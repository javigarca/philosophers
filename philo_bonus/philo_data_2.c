/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:19:28 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/13 10:37:08 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_sub(const char *str, char c)
{
	int	cont;
	int	sub;

	cont = 0;
	sub = 0;
	if (!str)
		return (0);
	while (*str != 00)
	{
		if (*str != c && sub == 0)
		{
			sub = 1;
			cont++;
		}
		else if (*str == c)
		{
			sub = 0;
		}
		str++;
	}
	return (cont);
}

int	ft_num_elem(char **data, int argc)
{
	char	**argument;
	char	**temp;
	int		i;
	int		elements;

	i = 1;
	elements = 0;
	while (i < argc)
	{
		argument = ft_split(data[i], ' ');
		temp = argument;
		while (*argument)
		{
			elements++;
			free(*argument);
			argument++;
		}
		free(temp);
		i++;
	}
	return (elements);
}

int	ft_check_dupl(t_dtint data)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < data.len)
	{
		while (++k < data.len)
		{
			if ((data.nb[i] == data.nb[k]) && (i != k))
				return (1);
		}
		k = 0;
		i++;
	}
	return (0);
}
