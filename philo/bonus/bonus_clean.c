/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_clean.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 15:56:34 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/03/09 11:56:10 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

static void	terminate_all(t_data *data);
static void	kill_all(t_data *data);
static void	free_data(t_data *data);
static void	close_semaphores(t_data *data);

void	cleanup(t_data *data)
{
	terminate_all(data);
	free_data(data);
}

static void	terminate_all(t_data *data)
{
	int	i;
	int status;

	i = 0;
	while (i < data->n_philo)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			printf("kill all\n");
			kill_all(data);
			break ;
		}
		i++;
	}
}

static void	kill_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->philos[i].pid > 0)
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
