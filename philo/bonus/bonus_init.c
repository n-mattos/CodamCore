/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:01:15 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/04 13:01:35 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

void	allocate_pids_threads(pid_t **pids, pthread_t **threads, \
		t_args *args, int number_of_philosophers)
{
	*pids = malloc(sizeof(pid_t) * number_of_philosophers);
	if (!*pids)
	{
		free(args);
		exit_error("malloc failed");
	}
	*threads = malloc(sizeof(pthread_t) * number_of_philosophers);
	if (!*threads)
	{
		free(args);
		free(*pids);
		exit_error("malloc failed");
	}
}

void	allocate_and_init_args(t_args **args, int argc, char *argv[])
{
	int	n_philo;

	*args = malloc(sizeof(t_args));
	if (*args == NULL)
		exit_error("malloc failed");
	*args = init_args(*args, argc, argv);
	if (!*args)
		exit_error("Invalid Arguments");
	n_philo = (*args)->number_of_philosophers;
	sem_unlink("/stop");
	(*args)->stop = sem_open("/stop", O_CREAT, 0644, n_philo);
	sem_unlink("/full");
	(*args)->full = sem_open("/full", O_CREAT, 0644, n_philo);
	sem_unlink("/forks");
	(*args)->forks = sem_open("/forks", O_CREAT, 0644, n_philo);
	if ((*args)->stop == SEM_FAILED
		|| (*args)->full == SEM_FAILED || (*args)->forks == SEM_FAILED)
	{
		free_args(*args);
		exit_error("sem_open failed");
	}
}

t_args	*init_args(t_args *args, int argc, char *argv[])
{
	int		error;

	if (argc < 5 || argc > 6)
		return (free(args), NULL);
	args->number_of_philosophers = ft_atoi(argv[1], &error);
	if (error || args->number_of_philosophers <= 0)
		return (free(args), NULL);
	args->time_to_die = ft_atoi(argv[2], &error);
	if (error || args->time_to_die <= 0)
		return (free(args), NULL);
	args->time_to_eat = ft_atoi(argv[3], &error);
	if (error || args->time_to_eat <= 0)
		return (free(args), NULL);
	args->time_to_sleep = ft_atoi(argv[4], &error);
	if (error || args->time_to_sleep <= 0)
		return (free(args), NULL);
	args->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 5)
		return (args);
	args->number_of_times_each_philosopher_must_eat \
	= ft_atoi(argv[5], &error);
	if (error || args->number_of_times_each_philosopher_must_eat <= 0)
		return (free(args), NULL);
	args->full_philos = 0;
	return (args);
}

void	init_philo(t_philo **philo, int i)
{
	(*philo)->id = i;
	(*philo)->state = ALIVE;
	(*philo)->number_of_meals = 0;
	gettimeofday(&(*philo)->last_meal, NULL);
}

t_data	*init_data(t_args *args, int i)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->args = args;
	data->philo = malloc(sizeof(t_philo));
	if (!data->philo)
	{
		free(data);
		return (NULL);
	}
	init_philo(&data->philo, i);
	sem_wait(data->args->stop);
	sem_wait(data->args->full);
	return (data);
}
