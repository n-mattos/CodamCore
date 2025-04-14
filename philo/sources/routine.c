/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:43:36 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/14 12:18:06 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	start_living(t_philo *p);
static bool	check_death(t_philo *p);

void	*philo_life(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	start_living(p);
	print_timestamp(p->id, "living");
	pthread_mutex_lock(&p->data->meal_lock);
	p->last_meal = get_current_time();
	pthread_mutex_unlock(&p->data->meal_lock);
	if (p->id % 2)
		ft_sleep_ms(p->data->eat_time * 0.9 + 1);
	while (1)
	{
		if (action_eat(p) == STOP)
			break ;
		if (check_death(p))
			break ;
		action_sleep(p);
		if (check_death(p))
			break ;
		print_timestamp(p->id, "is thinking");
	}
	return (NULL);
}

static void	start_living(t_philo *p)
{
	while (1)
	{
		pthread_mutex_lock(&p->data->time_lock);
		if (p->data->start)
		{
			pthread_mutex_unlock(&p->data->time_lock);
			break ;
		}
		pthread_mutex_unlock(&p->data->time_lock);
		ft_sleep_ms(1);
	}
}

static bool	check_death(t_philo *p)
{
	pthread_mutex_lock(&p->data->death_lock);
	if (p->data->corpse == true)
	{
		pthread_mutex_unlock(&p->data->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&p->data->death_lock);
	return (false);
}
