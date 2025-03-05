/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:58:30 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/04 12:49:43 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

void	free_all(pid_t *pids, pthread_t *threads, t_args *args)
{
	if (pids)
		free(pids);
	if (threads)
		free(threads);
	free_args(args);
}

void	free_args(t_args *args)
{
	sem_close(args->forks);
	sem_unlink("/forks");
	sem_close(args->stop);
	sem_unlink("/stop");
	sem_close(args->full);
	sem_unlink("/full");
	sem_close(args->exit);
	sem_unlink("/exit");
	if (args)
		free(args);
}

void	free_data(t_data *data)
{
	if (data->philo)
		free(data->philo);
	if (data)
		free(data);
}

void	exit_error_free(char *msg, pid_t *pids, pthread_t *thrd, t_args *args)
{
	free_all(pids, thrd, args);
	exit_error(msg);
}
