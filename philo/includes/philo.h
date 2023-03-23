/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:01:26 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/23 14:35:33 by javigarc         ###   ########.fr       */
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
	int				death;
	int				fat;
	pthread_mutex_t	message;
	pthread_mutex_t	genesis;
	pthread_mutex_t	changes;
}			t_env;

typedef struct s_philo
{
	int				p_id;
	pthread_t		t_id;
	int				meals_eaten;
	long long		last_meal;
	pthread_mutex_t	death;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_env			*env;
}			t_philo;

typedef struct s_table
{
	int				total_philos;
	pthread_t		aristotle;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	t_env			env;
}			t_table;

// philo_data //
void		ft_data_validation(char **data, int argc);
void		ft_set_table(char **data, int argc, t_table *table);
long		ft_myatoi(const char *str);
void		ft_free_table(t_table *table);
// philo_utils //
void		ft_exit_error(int err);
int			ft_write_str(char *str, int channel);
long long	ft_time_now(void);
long long	ft_timestamp(long long time);
void		ft_print(t_philo *philo, char *msg);
// philo_init //
void		ft_set_mutex(t_table *table);
void		ft_set_philos(t_table *table);
void		ft_set_forks(t_philo *philo, t_table *table);
void		ft_set_threads(t_table *table);
int			ft_start_threads(t_table *table);
// philo_threads //
void		*ft_philo_thread(void *args);
void		ft_sleep(long long time);
void		*ft_aristotle(void *args);
int			ft_check_death(t_philo *philo);
void		kill_table(t_table *table);
// philo_actions //
int			ft_philo_eats(t_philo *philo);
int			ft_philo_dies(t_philo *philo);
int			check_changes_table(t_table *table);
int			check_changes_philo(t_philo *philo);
#endif
