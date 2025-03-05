/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:56:34 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 16:53:26 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

static void	wait_for_threads(t_data *data);
static void	terminate_all(t_data *data);
static void	free_data(t_data *data);
static void	close_semaphores(t_data *data);

void	cleanup(t_data *data)
{
	sem_wait(data->exit);
	terminate_all(data);
	wait_for_threads(data);
	free_data(data);
}

static void	wait_for_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philos[i].monitor, NULL);
		i++;
	}
}

static void	terminate_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		kill(data->philos[i].pid, SIGKILL);
		i++;
	}
}

static void	free_data(t_data *data)
{
	free(data->philos);
	close_semaphores(data);
}

static void	close_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_unlink("/forks");
	sem_close(data->time_lock);
	sem_unlink("/time");
	sem_close(data->meal_lock);
	sem_unlink("/meal");
	sem_close(data->death_lock);
	sem_unlink("/death");
}
