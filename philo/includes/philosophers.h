/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:01:06 by nmattos           #+#    #+#             */
/*   Updated: 2025/03/05 15:27:23 by nmattos-         ###   ########.fr       */
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

# define STOP 0
# define CONTINUE 1

typedef struct s_philo
{
	int				id;
	int				lf;
	int				rf;
	size_t			last_meal;
	int				total_meals;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	bool			start;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			die_time;
	int				max_meals;
	bool			corpse;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	death_lock;
	t_philo			*philos;
}	t_data;

/*****************************************************************************\
|*                                Functions                                  *|
\*****************************************************************************/

/* checks.c */
void	check_args(int argc, char *argv[]);

/* init.c */
void	init_data(t_data *data, int argc, char *argv[]);
void	start_philos(t_data *data);

/* routine.c */
void	*philo_life(void *philo);

/* monitor.c */
void	start_monitor(t_data *data);

/* actions.c */
int		action_eat(t_philo *p);
void	action_sleep(t_philo *p);
void	action_think(t_philo *p);

/* forks.c */
void	take_forks(t_philo *p);
void	return_forks(t_philo *p);

/* utils.c */
int		ft_atoi(const char *nptr);
size_t	get_current_time(void);
void	ft_sleep_ms(size_t milliseconds);
void	print_timestamp(int id, char *message);
void	exit_error(char *message);

/* clean.c */
void	cleanup(t_data *data);

#endif
