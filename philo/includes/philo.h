/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/31 19:45:13 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	int			p_id;
	pthread_t	t_id;
	int			meals_eaten;
	long long	last_meal;
}			t_philo;

typedef struct s_env
{
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			times_m_eat;
	long long	start_time;
	int			total_philos;
	t_philo		*philos;

}			t_env;

// philo_time //
// philo_data //
void		ft_data_validation(char **data, int argc);
long		ft_myatoi(const char *str);
// philo_utils //
void		ft_exit_error(int err);
int			ft_write_str(char *str, int channel);
long long	ft_time_now(void);
 
// ps_actions_2 //
#endif
