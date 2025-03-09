/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_monitor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 15:59:44 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/03/09 11:55:17 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

static bool	corpse_found(t_philo *p);

void	*child_monitor(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	ft_sleep_ms(10);
	while (1)
	{
		if (corpse_found(p))
			break ;
		ft_sleep_ms(1);
	}
	return (NULL);
}

static bool	corpse_found(t_philo *p)
{
	int	delta_meal_time;

	sem_wait(p->data->meal_lock);
	delta_meal_time = (get_current_time() - p->last_meal);
	sem_post(p->data->meal_lock);
	sem_wait(p->data->death_lock);
	if (delta_meal_time > (int)p->data->die_time || p->data->corpse == true)
	{
		printf("corpse found: %d\n", p->data->corpse);
		if (p->data->corpse == false)
		{
			p->data->corpse = true;
			print_timestamp(p->id, "died");
		}
		sem_post(p->data->death_lock);
		return (true);
	}
	sem_post(p->data->death_lock);
	return (false);
}
