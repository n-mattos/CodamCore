/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_philos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 10:10:50 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/21 10:37:02 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	init_philo(t_data *data, int i);

int	start_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philos)
	{
		printf("Error: malloc failed\n");
		return (FAIL);
	}
	pthread_mutex_lock(&data->time_lock);
	i = 0;
	while (i < data->n_philo)
	{
		if (init_philo(data, i) == FAIL)
			return (FAIL);
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

static int	init_philo(t_data *data, int i)
{
	memset(&data->philos[i], 0, sizeof(t_philo));
	data->philos[i].id = i + 1;
	if (i > ((i + 1) % data->n_philo))
	{
		data->philos[i].lf = i;
		data->philos[i].rf = (i + 1) % data->n_philo;
	}
	else
	{
		data->philos[i].lf = (i + 1) % data->n_philo;
		data->philos[i].rf = i;
	}
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
	return (SUCCESS);
}
