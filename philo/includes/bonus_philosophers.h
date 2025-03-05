/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:39:35 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 16:47:50 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILOSOPHERS_H
# define BONUS_PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>

# define STOP 0
# define CONTINUE 1

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	size_t			last_meal;
	int				total_meals;
	pthread_t		monitor;
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
	sem_t			*forks;
	sem_t			*time_lock;
	sem_t			*meal_lock;
	sem_t			*death_lock;
	sem_t			*exit;
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
void	*child_monitor(void *philo);

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