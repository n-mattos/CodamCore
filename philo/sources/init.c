/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 12:23:29 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/04/17 14:12:19 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int				init_mutexes(t_data *data);
static pthread_mutex_t	*initialize_mutex_array(int size);
static void				free_mutex(pthread_mutex_t *mutexes, int size);

int	init_data(t_data *data, int argc, char *argv[])
{
	memset(data, 0, sizeof(t_data));
	data->n_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	if (data->n_philo == -1 || data->die_time == -1 ||
		data->eat_time == -1 || data->sleep_time == -1 || data->max_meals == -1)
	{
		printf("Error: given number is too large\n");
		return (FAIL);
	}
	if (data->max_meals == 0)
		data->max_meals = -1;
	if (init_mutexes(data) == -1)
	{
		printf("Error: mutex initialization failed\n");
		return (FAIL);
	}
	return (SUCCESS);
}

int	start_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philos)
	{
		printf("Error: malloc failed\n");
		return (FAIL);
	}
	i = 0;
	pthread_mutex_lock(&data->time_lock);
	while (i < data->n_philo)
	{
		memset(&data->philos[i], 0, sizeof(t_philo));
		data->philos[i].id = i + 1;
		data->philos[i].lf = i;
		data->philos[i].rf = (i + 1) % data->n_philo;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].card, NULL) == -1)
		{
			pthread_mutex_unlock(&data->time_lock);
			return (FAIL);
		}
		if (pthread_create(&data->philos[i].thread, NULL, \
			&philo_life, &data->philos[i]) == -1)
		{
			pthread_mutex_unlock(&data->time_lock);
			return (FAIL);
		}
		i++;
	}
	i = 0;
	while (i < data->n_philo)
		data->philos[i++].last_meal = get_current_time();
	data->start = true;
	data->start_time = get_current_time();
	pthread_mutex_unlock(&data->time_lock);
	return (SUCCESS);
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
	if (pthread_mutex_init(&data->print_lock, NULL) == -1)
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
		pthread_mutex_destroy(&data->print_lock);
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
