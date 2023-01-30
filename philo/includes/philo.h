/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/30 18:15:30 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_table
{
	int				data;
	int				index;
	int				key;
}			t_table;
typedef struct s_philo
{
	int	*nb;
	int	len;
}			t_philo;
// philo_time //
// philo_data //
void	ft_data_validation(char **data, int argc);
long	ft_myatoi(const char *str);
// philo_utils //
void	ft_exit_error(void);
void	ft_pr_action(int op);
 
// ps_actions_2 //
#endif
