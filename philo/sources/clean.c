/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:21:33 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/17 13:35:19 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_mutex(pthread_mutex_t *mutexes, int size)
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

void	free_args(t_args *args)
{
	pthread_mutex_lock(args->morgue);
	free_mutex(args->full_philos, args->number_of_philosophers);
	pthread_mutex_unlock(args->morgue);
	free_mutex(args->death, args->number_of_philosophers);
	free_mutex(args->morgue, 1);
	free(args);
}

void	free_forks(t_forks *forks, int n_forks)
{
	free_mutex(forks->mutexes, n_forks);
	free(forks->available);
	free_mutex(forks->grab, 1);
	free(forks);
}

void	free_threads(pthread_t *threads, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		// pthread_detach(threads[i]);
		i++;
	}
	free(threads);
}

void	free_data(t_data *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (data[i].philo)
			free(data[i].philo);
		i++;
	}
	free(data);
}
