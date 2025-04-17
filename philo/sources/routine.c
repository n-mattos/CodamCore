/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 12:43:36 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/04/17 15:30:29 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_life(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	pthread_mutex_lock(&p->data->time_lock);
	if (p->data->start == false)
	{
		return (NULL);
	}
	pthread_mutex_unlock(&p->data->time_lock);
	if (p->data->n_philo == 1)
		return (ft_sleep_ms(p, p->data->die_time), NULL);
	if (p->id % 2 == 0)
		ft_sleep_ms(p, p->data->eat_time * 0.5);
	while (1)
	{
		if (action_eat(p) == STOP)
			break ;
		if (check_death(p))
			break ;
		if (action_sleep(p) == STOP)
			break ;
		if (check_death(p))
			break ;
		if (action_think(p) == STOP)
			break ;
		if (check_death(p))
			break ;
	}
	return (NULL);
}

bool	check_death(t_philo *p)
{
	int	delta_meal_time;

	delta_meal_time = (get_current_time() - p->last_meal);
	if (delta_meal_time > (int)p->data->die_time || p->state == DEAD)
	{
		p->state = DEAD;
		return (true);
	}
	return (false);
}
