/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/03 22:07:32 by javigarc         ###   ########.fr       */
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

typedef struct s_env
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_m_eat;
	long long		start_time;
}			t_env;

typedef struct s_philo
{
	int				p_id;
	pthread_t		t_id;
	int				meals_eaten;
	long long		last_meal;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	int				dead;
	t_env			env;
}			t_philo;

typedef struct	s_table
{
	int				total_philos;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	t_env			env;
}			t_table;

// philo_data //
void		ft_data_validation(char **data, int argc);
void		ft_set_table(char **data, int argc, t_table *table);
long		ft_myatoi(const char *str);
// philo_utils //
void		ft_exit_error(int err);
int			ft_write_str(char *str, int channel);
long long	ft_time_now(void);
// philo_init //
void		ft_set_mutex(t_table *table);
void		ft_set_philos(t_table *table);
void		ft_set_forks(t_philo *philo, t_table *table);
void		ft_set_threads(t_table *table);
// philo_threads //
void		*ft_philo_thread(void *args);
#endif
