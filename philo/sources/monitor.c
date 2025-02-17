/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:48:48 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/17 13:36:17 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	*check_stomach(void *args);

void	stop_threads(t_args *args)
{
	pthread_t	full_thread;

	ft_sleep_ms(50);
	pthread_create(&full_thread, NULL, &check_stomach, args);
	ft_sleep_ms(50);
	while (1)
	{
		pthread_mutex_lock(args->morgue);
		if (*(args)->escape == true)
		{
			pthread_mutex_unlock(args->morgue);
			break ;
		}
		pthread_mutex_unlock(args->morgue);
		ft_sleep_ms(1);
	}
	pthread_detach(full_thread);
}

static void	*check_stomach(void *args)
{
	t_args	*arg;
	int		i;

	arg = (t_args *)args;
	i = 0;
	while (i < arg->number_of_philosophers)
	{
		pthread_mutex_lock(&arg->full_philos[i]);
		i++;
	}
	pthread_mutex_lock(arg->morgue);
	i = 0;
	while (i < arg->number_of_philosophers)
	{
		pthread_mutex_unlock(&arg->full_philos[i]);
		i++;
	}
	*(arg)->escape = true;
	pthread_mutex_unlock(arg->morgue);
	return (NULL);
}
