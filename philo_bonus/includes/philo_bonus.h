/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:01:26 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/28 21:50:29 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
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
	sem_t			sem_message;
	sem_t			sem_forks;
}			t_env;

typedef struct s_philo
{
	int				philo_id;
	pid_t			p_id;
	int				meals_eaten;
	long long		last_meal;
	t_env			*env;
}			t_philo;

typedef struct s_table
{
	int				total_philos;
	pthread_t		aristotle;
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
void		ft_set_semaphores(t_table *table);
void		ft_set_philos(t_table *table);
// philo_academia //
void		ft_philo_life(t_philo *philo);
void		ft_sleep(long long time, int *death);
void		*ft_aristotle(void *args);
int			ft_check_death(t_table *academia);
// philo_actions //
int			ft_philo_eats(t_philo *philo);
int			ft_philo_sleeps(t_philo *philo);
int			ft_philo_thinks(t_philo	*philo);
int			ft_philo_dies(t_philo *philo);
#endif
