/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_routine.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 16:06:05 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/03/09 11:53:21 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

// static void	start_living(t_philo *p);
// static bool	check_death(t_philo *p);

void	*philo_life(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	// start_living(p);
	sem_wait(p->data->exit);
	sem_wait(p->data->meal_lock);
	p->last_meal = get_current_time();
	sem_post(p->data->meal_lock);
	if (p->id % 2)
		ft_sleep_ms(p->data->eat_time * 0.9 + 1);
	while (1)
	{
		if (action_eat(p) == STOP)
			break ;
		// if (check_death(p))
		// 	break ;
		action_sleep(p);
		// if (check_death(p))
		// 	break ;
		action_think(p);
	}
	sem_post(p->data->exit);
	return (NULL);
}

// static void	start_living(t_philo *p)
// {
// 	while (1)
// 	{
// 		sem_wait(p->data->time_lock);
// 		if (p->data->start)
// 		{
// 			sem_post(p->data->time_lock);
// 			break ;
// 		}
// 		sem_post(p->data->time_lock);
// 		ft_sleep_ms(1);
// 	}
// }

// static bool	check_death(t_philo *p)
// {
// 	sem_wait(p->data->death_lock);
// 	if (p->data->corpse == true)
// 	{
// 		sem_post(p->data->death_lock);
// 		return (true);
// 	}
// 	sem_post(p->data->death_lock);
// 	return (false);
// }
