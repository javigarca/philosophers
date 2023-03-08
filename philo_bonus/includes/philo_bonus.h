/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:01:26 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/08 17:43:23 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_env
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_m_eat;
	long long		start_time;
	int				death;
	sem_t			*sem_message;
	sem_t			*sem_dead;
	sem_t			*sem_forks;
}			t_env;

typedef struct s_philo
{
	int				p_id;
	pid_t			f_id;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		aristotle;
	t_env			*env;
}			t_philo;

typedef struct s_table
{
	int				total_philos;
	t_philo			*philos;
	t_env			env;
}			t_table;

// philo_process //
void		ft_start_process(t_table *table);
void		ft_stop_process(t_table *table);
// philo_utils //
void		ft_exit_error(int err);
int			ft_write_str(char *str, int channel);
long long	ft_time_now(void);
long long	ft_timestamp(long long time);
void		ft_print(t_philo *philo, char *msg);
// philo_utils_2 //
void		ft_free_table(t_table *table);
long		ft_myatoi(const char *str);
void		ft_sleep(long long time, int *death);
// philo_set //
void		ft_set_semaphores(t_table *table);
void		ft_set_philos(t_table *table);
void		ft_data_validation(char **data, int argc);
void		ft_set_table(char **data, int argc, t_table *table);
// philo_run //
void		ft_philo_life(t_philo *philo);
int			ft_philo_eats(t_philo *philo);
int			ft_philo_dies(t_philo *philo);
void		*ft_aristotle(void *args);
int			ft_check_death(t_philo *philo);

#endif
