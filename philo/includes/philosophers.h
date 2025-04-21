/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 13:01:06 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/21 10:11:12 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

# define STOP 0
# define CONTINUE 1

# define SUCCESS 0
# define FAIL 1

# define ALIVE 0
# define DEAD 1

typedef struct s_philo
{
	int				id;
	int				lf;
	int				rf;
	size_t			last_meal;
	int				total_meals;
	int				state;
	pthread_t		thread;
	pthread_mutex_t	card;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	bool			start;
	ssize_t			start_time;
	ssize_t			eat_time;
	ssize_t			sleep_time;
	ssize_t			die_time;
	int				max_meals;
	int				full_philos;
	bool			corpse;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
}	t_data;

/*****************************************************************************\
|*                                Functions                                  *|
\*****************************************************************************/

/* checks.c */
int		check_args(int argc, char *argv[]);

/* init.c */
int		init_data(t_data *data, int argc, char *argv[]);

/* start_philos */
int		start_philos(t_data *data);

/* routine.c */
void	*philo_life(void *philo);
bool	check_death(t_philo *p);

/* monitor.c */
void	run_monitor(void *data);

/* actions.c */
int		action_eat(t_philo *p);
int		action_sleep(t_philo *p);
int		action_think(t_philo *p);

/* forks.c */
int		take_forks(t_philo *p);
void	return_forks(t_philo *p);

/* utils.c */
int		ft_atoi(const char *nptr);
size_t	get_current_time(void);
int		ft_sleep_ms(t_philo *p, size_t milliseconds);
void	ft_sleep_process_ms(size_t milliseconds);
void	print_timestamp(t_philo *p, char *message);

/* clean.c */
void	cleanup(t_data *data);

#endif
