/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:01 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/11 15:40:34 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>

# define ALIVE 0
# define DEAD 1
# define FULL 2
# define ESCAPE 3

typedef struct	s_args
{
	pthread_mutex_t	*full_philos;
	pthread_mutex_t	*death;
	pthread_mutex_t	*morgue;
	bool			*escape;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}	t_args;

typedef struct	s_philo
{
	int				id;
	int				state;
	int				number_of_meals;
	int				left_fork;
	int				right_fork;
	struct timeval	last_meal;
}	t_philo;

typedef struct	s_forks
{
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	*grab;
	bool			*available;
}	t_forks;

typedef struct	s_data
{
	t_args		*args;
	t_forks		*forks;
	t_philo		*philo;
}	t_data;

/* checks.c */
void	check_args(int argc, char *argv[]);

/* init.c */
t_args	*init_args(int argc, char *argv[]);
t_forks	*init_forks(t_args *args);
pthread_t	*init_threads(t_args *args, t_forks *forks);
t_data	*init_data(t_args *args, t_forks *forks, pthread_t *threads, int i);
t_philo	*init_philo(t_args *args, t_forks *forks, pthread_t *threads, int i);

/* init_mutex.c */
t_args	*initialize_args_mutexes(t_args *args);
pthread_mutex_t	*initialize_mutex_array(int size);

/* routine.c */
void	*philosopher_life(void *data_void);

/* actions.c */
void	die(t_data *data);
void	eat(t_data *data);
bool	is_starving(t_data *data);
void	think(t_data *data);
void	go_to_sleep(t_data *data);

/* forks.c */
bool	take_forks(t_data *data);
void	return_forks(t_data *data);

/* monitor.c */
void	stop_threads(t_args *args);

/* print.c */
void	print_timestamp(int id, char *message);
void	exit_error(char *message);

/* utils.c */
int		ft_atoi(const char *nptr);
size_t	get_ms(struct timeval time);
size_t	get_current_time(void);
void	ft_sleep_ms(size_t milliseconds);

/* clean.c */
void	free_mutex(pthread_mutex_t *mutexes, int size);
void	free_args(t_args *args);
void	free_forks(t_forks *forks, int n_forks);
void	free_threads(pthread_t *threads, int size);
void	free_data(t_data *data, int size);

#endif
