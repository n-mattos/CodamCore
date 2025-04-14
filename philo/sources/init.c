/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:23:29 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/14 12:24:47 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int				init_mutexes(t_data *data);
static pthread_mutex_t	*initialize_mutex_array(int size);
static void				free_mutex(pthread_mutex_t *mutexes, int size);

void	init_data(t_data *data, int argc, char *argv[])
{
	data->n_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->start = false;
	data->max_meals = -1;
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	data->corpse = false;
	if (init_mutexes(data) == -1)
	{
		printf("Error: mutex initialization failed\n");
		exit(1);
	}
}

void	start_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philos)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	data->start_time = get_current_time();
	i = 0;
	while (i < data->n_philo)
	{
		data->philos[i].id = i;
		data->philos[i].lf = i;
		data->philos[i].rf = (i + 1) % data->n_philo;
		data->philos[i].total_meals = 0;
		data->philos[i].data = data;
		pthread_create(&data->philos[i].thread, NULL, \
			&philo_life, &data->philos[i]);
		i++;
	}
	pthread_mutex_lock(&data->time_lock);
	data->start = true;
	pthread_mutex_unlock(&data->time_lock);
}

static int	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->time_lock, NULL) == -1)
		return (-1);
	if (pthread_mutex_init(&data->meal_lock, NULL) == -1)
	{
		pthread_mutex_destroy(&data->time_lock);
		return (-1);
	}
	if (pthread_mutex_init(&data->death_lock, NULL) == -1)
	{
		pthread_mutex_destroy(&data->time_lock);
		pthread_mutex_destroy(&data->meal_lock);
		return (-1);
	}
	data->forks = initialize_mutex_array(data->n_philo);
	if (!data->forks)
	{
		pthread_mutex_destroy(&data->time_lock);
		pthread_mutex_destroy(&data->meal_lock);
		pthread_mutex_destroy(&data->death_lock);
		return (-1);
	}
	return (0);
}

static pthread_mutex_t	*initialize_mutex_array(int size)
{
	pthread_mutex_t	*mutexes;
	int				i;

	mutexes = malloc(sizeof(pthread_mutex_t) * size);
	if (!mutexes)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&mutexes[i], NULL) == -1)
		{
			free_mutex(mutexes, i);
			return (NULL);
		}
		i++;
	}
	return (mutexes);
}

static void	free_mutex(pthread_mutex_t *mutexes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&mutexes[i]);
		i++;
	}
	free(mutexes);
}
