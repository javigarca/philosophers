/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/14 14:59:27 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_dtint	data;

	if (argc == 1)
		exit(0);
	ft_data_validation(argv, argc);
	data = ft_data_load(argv, argc);
	if (ft_check_dupl(data))
	{
		free(data.nb);
		ft_exit_error();
	}
	stack_a = ft_build_stack(data);
	if (!ft_issorted(stack_a))
	{
		ft_stack_keying(&stack_a);
		ft_stack_indexing(&stack_a);
		ft_sort_select(stack_a);
	}
	free(data.nb);
	ft_stack_free(&stack_a);
	return (0);
}
