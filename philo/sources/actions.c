/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:51:23 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 14:12:38 by nmattos-         ###   ########.fr       */
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
	pthread_mutex_lock(&p->data->death_lock);
	if (p->data->corpse == true)
	{
		pthread_mutex_unlock(&p->data->death_lock);
		return_forks(p);
		return (STOP);
	}
	pthread_mutex_unlock(&p->data->death_lock);
	pthread_mutex_lock(&p->data->meal_lock);
	p->last_meal = get_current_time();
	p->total_meals++;
	pthread_mutex_unlock(&p->data->meal_lock);
	print_timestamp(p->id, "is eating");
	ft_sleep_ms(p->data->eat_time);
	return_forks(p);
	return (CONTINUE);
}

void	action_think(t_philo *p)
{
	int	think_time;
	int	time_since_last_meal;

	print_timestamp(p->id, "is thinking");
	time_since_last_meal = \
		(get_current_time() \
		- p->last_meal);
	think_time = \
		(p->data->die_time \
		- time_since_last_meal \
		- p->data->eat_time) \
		/ 2;
	if (think_time > 0)
		ft_sleep_ms(think_time);
}

void	action_sleep(t_philo *p)
{
	print_timestamp(p->id, "is sleeping");
	ft_sleep_ms(p->data->sleep_time);
}
