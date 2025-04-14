/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:51:23 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/14 12:25:49 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	action_eat(t_philo *p)
{
	if (p->data->n_philo == 1)
	{
		ft_sleep_ms(p->data->die_time);
		return (STOP);
	}
	take_forks(p);
	pthread_mutex_lock(&p->data->meal_lock);
	pthread_mutex_lock(&p->data->death_lock);
	if (p->data->corpse == true)
	{
		pthread_mutex_unlock(&p->data->meal_lock);
		pthread_mutex_unlock(&p->data->death_lock);
		return_forks(p);
		return (STOP);
	}
	pthread_mutex_unlock(&p->data->death_lock);
	p->last_meal = get_current_time();
	p->total_meals++;
	pthread_mutex_unlock(&p->data->meal_lock);
	print_timestamp(p->data->start_time, p->id, "is eating");
	ft_sleep_ms(p->data->eat_time);
	return_forks(p);
	return (CONTINUE);
}

void	action_sleep(t_philo *p)
{
	print_timestamp(p->data->start_time, p->id, "is sleeping");
	ft_sleep_ms(p->data->sleep_time);
}
