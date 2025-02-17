/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:10:45 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/11 11:47:15 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_args	*initialize_args_mutexes(t_args *args)
{
	args->full_philos = initialize_mutex_array(args->number_of_philosophers);
	if (!args->full_philos)
	{
		free(args);
		exit_error("creating mutexes failed");
	}
	args->death = initialize_mutex_array(args->number_of_philosophers);
	if (!args->death)
	{
		free_mutex(args->full_philos, args->number_of_philosophers);
		free(args);
		exit_error("creating mutexes failed");
	}
	args->morgue = initialize_mutex_array(1);
	if (!args->morgue)
	{
		free_mutex(args->full_philos, args->number_of_philosophers);
		free_mutex(args->death, args->number_of_philosophers);
		free(args);
		exit_error("creating mutexes failed");
	}
	return (args);
}

pthread_mutex_t	*initialize_mutex_array(int size)
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

