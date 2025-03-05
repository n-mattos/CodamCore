/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:09:03 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 16:50:28 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

int	action_eat(t_philo *p)
{
	if (p->data->n_philo == 1)
	{
		ft_sleep_ms(p->data->die_time);
		return (STOP);
	}
	take_forks(p);
	sem_wait(p->data->death_lock);
	if (p->data->corpse == true)
	{
		sem_post(p->data->death_lock);
		return_forks(p);
		return (STOP);
	}
	sem_post(p->data->death_lock);
	sem_wait(p->data->meal_lock);
	p->last_meal = get_current_time();
	p->total_meals++;
	sem_post(p->data->meal_lock);
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
