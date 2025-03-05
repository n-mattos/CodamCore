/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:08:36 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 13:10:56 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_forks(t_philo *p)
{
	if (p->lf > p->rf)
	{
		pthread_mutex_lock(&p->data->forks[p->rf]);
		pthread_mutex_lock(&p->data->forks[p->lf]);
	}
	else
	{
		pthread_mutex_lock(&p->data->forks[p->lf]);
		pthread_mutex_lock(&p->data->forks[p->rf]);
	}
}

void	return_forks(t_philo *p)
{
	if (p->lf > p->rf)
	{
		pthread_mutex_unlock(&p->data->forks[p->lf]);
		pthread_mutex_unlock(&p->data->forks[p->rf]);
	}
	else
	{
		pthread_mutex_unlock(&p->data->forks[p->rf]);
		pthread_mutex_unlock(&p->data->forks[p->lf]);
	}
}
