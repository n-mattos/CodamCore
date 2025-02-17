/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:43:37 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/11 15:32:14 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_args	*init_args(int argc, char *argv[])
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		exit_error("malloc failed");
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	args = initialize_args_mutexes(args);
	return (args);
}

t_forks	*init_forks(t_args *args)
{
	t_forks	*forks;

	forks = malloc(sizeof(t_forks));
	if (!forks)
		exit_error("malloc failed");
	forks->available = malloc(sizeof(bool) * args->number_of_philosophers);
	if (!forks->available)
	{
		free(forks);
		exit_error("malloc failed");
	}
	memset(forks->available, true, args->number_of_philosophers);
	forks->mutexes = initialize_mutex_array(args->number_of_philosophers);
	if (!forks->mutexes)
	{
		free(forks);
		free(forks->available);
		exit_error("creating mutexes failed");
	}
	forks->grab = initialize_mutex_array(1);
	if (!forks->grab)
	{
		free(forks->mutexes);
		free(forks);
		free(forks->available);
		exit_error("creating mutexes failed");
	}
	return (forks);
}

pthread_t	*init_threads(t_args *args, t_forks *forks)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * args->number_of_philosophers);
	if (!threads)
	{
		free_args(args);
		free_forks(forks, args->number_of_philosophers);
		exit_error("malloc failed");
	}
	return (threads);
}

t_data	*init_data(t_args *args, t_forks *forks, pthread_t *threads, int i)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * args->number_of_philosophers);
	if (!data)
	{
		free_args(args);
		free_forks(forks, args->number_of_philosophers);
		free_threads(threads, i);
		exit_error("malloc failed");
	}
	return (data);
}

t_philo	*init_philo(t_args *args, t_forks *forks, pthread_t *threads, int i)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		free_args(args);
		free_forks(forks, args->number_of_philosophers);
		free_threads(threads, i);
		exit_error("malloc failed");
	}
	philo->id = i;
	philo->state = ALIVE;
	philo->number_of_meals = 0;
	philo->left_fork = i;
	philo->right_fork = (i + 1) % args->number_of_philosophers;
	gettimeofday(&philo->last_meal, NULL);
	return (philo);
}
