/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 13:44:57 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/04/17 14:17:08 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	wait_for_threads(t_data *data);
static void	free_data(t_data *data);
static void	free_forks(t_data *data);

void	cleanup(t_data *data)
{
	wait_for_threads(data);
	free_data(data);
}

static void	wait_for_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

static void	free_data(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->time_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->print_lock);
	i = 0;
	while (i < data->n_philo)
		pthread_mutex_destroy(&data->philos[i++].card);
	free(data->philos);
	free_forks(data);
}

static void	free_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}
