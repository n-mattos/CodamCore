/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 16:51:23 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/04/17 15:33:54 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	action_eat(t_philo *p)
{
	if (take_forks(p) == STOP)
	{
		return (STOP);
	}
	pthread_mutex_lock(&p->card);
	if (check_death(p))
	{
		pthread_mutex_unlock(&p->card);
		return_forks(p);
		return (STOP);
	}
	p->last_meal = get_current_time();
	p->total_meals++;
	pthread_mutex_unlock(&p->card);
	print_timestamp(p, "is eating");
	if (ft_sleep_ms(p, p->data->eat_time) == STOP)
	{
		return_forks(p);
		return (STOP);
	}
	return_forks(p);
	if (p->total_meals == p->data->max_meals)
	{
		pthread_mutex_lock(&p->data->meal_lock);
		p->data->full_philos += 1;
		pthread_mutex_unlock(&p->data->meal_lock);
	}
	return (CONTINUE);
}

int		action_sleep(t_philo *p)
{
	print_timestamp(p, "is sleeping");
	if (ft_sleep_ms(p, p->data->sleep_time) == STOP)
		return (STOP);
	return (CONTINUE);
}

int		action_think(t_philo *p)
{
	int	pondering_time;

	print_timestamp(p, "is thinking");
	pthread_mutex_lock(&p->card);
	pondering_time = p->data->die_time - (get_current_time() - p->last_meal);
	// pondering_time = p->data->eat_time - p->data->sleep_time;
	// printf("<%d>\n", pondering_time);
	pthread_mutex_unlock(&p->card);
	if (pondering_time > 0)
		if (ft_sleep_ms(p, pondering_time) == STOP)
			return (STOP);
	return (CONTINUE);
}