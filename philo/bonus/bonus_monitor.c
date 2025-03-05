/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:59:44 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 16:50:56 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

static bool	corpse_found(t_philo *p);

void	*child_monitor(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	printf("Thread started\n");
	ft_sleep_ms(10);
	while (1)
	{
		if (corpse_found(p))
			break ;
		ft_sleep_ms(5);
	}
	printf("Thread %d finished\n", p->id);
	return (NULL);
}

static bool	corpse_found(t_philo *p)
{
	int	delta_meal_time;

	sem_wait(p->data->meal_lock);
	delta_meal_time = (get_current_time() - p->last_meal);
	sem_post(p->data->meal_lock);
	if (delta_meal_time > (int)p->data->die_time)
	{
		sem_wait(p->data->death_lock);
		if (p->data->corpse == false)
		{
			p->data->corpse = true;
			print_timestamp(p->id, "died");
		}
		sem_post(p->data->death_lock);
		return (true);
	}
	return (false);
}
