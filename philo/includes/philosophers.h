/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 13:01:06 by nmattos       #+#    #+#                 */
/*   Updated: 2025/02/27 13:09:14 by nmattos       ########   odam.nl         */
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

typedef struct s_philo
{
	int				id;
	int				lf;
	int				rf;
	time_t			last_meal;
	int				total_meal;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	time_t			start_time;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				max_meal;
	bool			corpse;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	death_lock;
	t_philo			*philos;
}	t_data;

#endif
