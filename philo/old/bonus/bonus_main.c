/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:39:07 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/04 13:01:41 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

static void	execute_processes(t_args *args, pid_t *pids, pthread_t *threads);
static void	terminate_all(pid_t *pids, t_args *args);

int	main(int argc, char *argv[])
{
	pid_t		*pids;
	pthread_t	*threads;
	t_args		*args;

	if (argc != 5 && argc != 6)
		exit_error("wrong number of arguments");
	args = NULL;
	allocate_and_init_args(&args, argc, argv);
	allocate_pids_threads(&pids, &threads, args, args->number_of_philosophers);
	execute_processes(args, pids, threads);
	stop_threads(args, pids, threads);
	terminate_all(pids, args);
	free_all(pids, threads, args);
	return (0);
}

static void	execute_processes(t_args *args, pid_t *pids, pthread_t *threads)
{
	int		i;
	t_data	*data;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			data = init_data(args, i);
			if (!data)
				exit_error_free("malloc failed", pids, threads, args);
			if (pthread_create(&threads[i], NULL, &child_monitor, (void *)data))
				exit_error("Failed to create thread");
			philosopher_life(data);
			pthread_join(threads[i], NULL);
			free_data(data);
			exit(0);
		}
		i++;
	}
}

static void	terminate_all(pid_t *pids, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		kill(pids[i], SIGKILL);
		i++;
	}
	i = 0;
	while (i < args->number_of_philosophers)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}
