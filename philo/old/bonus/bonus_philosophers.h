/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:39:35 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/04 12:39:50 by nmattos-         ###   ########.fr       */
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

# define ALIVE 0
# define DEAD 1
# define FULL 2

typedef struct s_args
{
	sem_t		*forks;
	sem_t		*stop;
	sem_t		*full;
	sem_t		*exit;
	int			full_philos;
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				state;
	int				number_of_meals;
	struct timeval	last_meal;
}	t_philo;

typedef struct s_data
{
	t_args		*args;
	t_philo		*philo;
}	t_data;

/* bonus_monitor.c */
void	*child_monitor(void *test);
void	stop_threads(t_args *args, pid_t *pids, pthread_t *threads);

/* bonus_utils.c */
size_t	get_current_time(void);
void	ft_sleep_ms(size_t milliseconds);
int		ft_atoi(const char *nptr, int *error);
size_t	get_ms(struct timeval time);

/* bonus_actions.c */
void	die(int id);
void	eat(t_data *data);
void	think(t_data *data);
void	go_to_sleep(t_data *data);

/* bonus_routine.c */
void	philosopher_life(t_data *data);

/* bonus_init.c */
void	allocate_and_init_args(t_args **args, int argc, char *argv[]);
void	allocate_pids_threads(pid_t **pids, pthread_t **threads, \
		t_args *args, int number_of_philosophers);
t_args	*init_args(t_args *args, int argc, char *argv[]);
void	init_philo(t_philo **philo, int i);
t_data	*init_data(t_args *args, int i);

/* bonus_clean.c */
void	free_all(pid_t *pids, pthread_t *threads, t_args *args);
void	free_args(t_args *args);
void	free_data(t_data *data);
void	exit_error_free(char *msg, pid_t *pids, pthread_t *thrd, t_args *args);

/* bonus_print.c */
void	print_timestamp(int id, char *message);
void	exit_error(char *message);

/* bonus_forks.c */
bool	take_forks(sem_t **forks);
void	return_forks(sem_t **forks);

#endif