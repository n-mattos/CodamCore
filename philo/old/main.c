/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:23:36 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/03 12:11:01 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_data	*execute_threads(t_args *args, pthread_t *threads, \
		t_forks *forks, bool *escape);
static void	wait_for_threads(t_args *args, pthread_t *threads);

int	main(int argc, char *argv[])
{
	t_args		*args;
	t_forks		*forks;
	pthread_t	*threads;
	t_data		*data;
	bool		escape;

	escape = false;
	check_args(argc, argv);
	args = init_args(argc, argv);
	forks = init_forks(args);
	threads = init_threads(args, forks);

	data = execute_threads(args, threads, forks, &escape);
	stop_threads(args);
	wait_for_threads(args, threads);

	// free all
	free(threads);
	free_data(data, args->number_of_philosophers);
	free_forks(forks, args->number_of_philosophers);
	free_args(args);
	return (0);
}

static t_data	*execute_threads(t_args *args, pthread_t *threads, \
		t_forks *forks, bool *escape)
{
	t_data		*data;
	int			i;

	i = 0;
	data = init_data(args, forks, threads, i);
	while (i < args->number_of_philosophers)
	{
		data[i].args = args;
		data[i].forks = forks;
		data[i].philo = init_philo(args, forks, threads, i);
		pthread_mutex_lock(args->morgue);
		data->args->escape = escape;
		pthread_mutex_unlock(args->morgue);
		if (pthread_create(&threads[i], NULL, &philosopher_life, &data[i]) != 0)
		{
			free_args(args);
			free_forks(forks, args->number_of_philosophers);
			free_threads(threads, args->number_of_philosophers);
			free_data(data, i);
			exit_error("Failed to create thread");
		}
		i++;
	}
	return (data);
}

static void	wait_for_threads(t_args *args, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
