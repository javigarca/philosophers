/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:19:28 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/13 21:21:15 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_data_validation(char **data, int argc)
{
	char	**argument;
	char	**temp;
	int		i;
	long	chk;

	i = 1;
	while (i < argc)
	{
		argument = ft_split(data[i], ' ');
		temp = argument;
		while (*argument)
		{
			if (!(ft_is_all_num(*argument)) || (ft_is_all_space(*argument)))
				ft_exit_error();
			chk = ft_myatoi(*argument);
			if ((chk < INT_MIN) || (chk > INT_MAX))
				ft_exit_error();
			free(*argument);
			argument++;
		}
		free(temp);
		i++;
	}
}

int	ft_data_duplication(t_stack *stack)
{
	int		i;
	int		k;
	int		len;
	t_stack	*temp;

	k = 0;
	i = 0;
	len = ft_stack_len(stack);
	temp = stack;
	while (i < ft_stack_len(stack))
	{
		while (k < ft_stack_len(stack))
		{
			if ((stack->data == temp->data) && (i != k))
				return (1);
			k++;
			temp = temp->next;
		}
		k = 0;
		stack = stack->next;
		i++;
	}
	return (0);
}

int	ft_is_all_space(char *data)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = data;
	while (*tmp)
	{
		if ((*tmp > 8 && *tmp < 14) || (*tmp == 32))
			i++;
		tmp++;
	}
	if (i == ft_strlen(data))
		return (1);
	return (0);
}

int	ft_is_all_num(char *data)
{
	if (!data)
		return (0);
	while (*data)
	{
		if (!ft_isdigit(*data))
			if (!ft_isspace(*data) && !ft_issign(*data))
				return (0);
		data++;
	}
	return (1);
}

t_dtint	ft_data_load(char **data, int argc)
{
	char	**argument;
	char	**temp;
	t_dtint	datareturn;
	int		i;
	int		k;

	i = 1;
	k = 0;
	datareturn.nb = (int *) malloc(sizeof (int *) * (ft_num_elem(data, argc)));
	while (i < argc)
	{
		argument = ft_split(data[i++], ' ');
		temp = argument;
		while (*argument)
		{
			datareturn.nb[k] = ft_myatoi(*argument);
			free(*argument);
			argument++;
			k++;
		}
		free(temp);
	}
	datareturn.len = k;
	return (datareturn);
}
