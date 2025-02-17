/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:02:35 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/04 11:50:40 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

void	die(int id)
{
	print_timestamp(id, "died");
}

void	eat(t_data *data)
{
	gettimeofday(&data->philo->last_meal, NULL);
	data->philo->number_of_meals++;
	print_timestamp(data->philo->id, "is eating");
	if (data->philo->state != FULL)
	{
		if (data->args->number_of_times_each_philosopher_must_eat != -1
			&& data->philo->number_of_meals
			>= data->args->number_of_times_each_philosopher_must_eat)
		{
			data->philo->state = FULL;
			sem_post(data->args->full);
		}
	}
	ft_sleep_ms(data->args->time_to_eat);
}

void	think(t_data *data)
{
	int				think_time;
	int				time_since_last_meal;

	print_timestamp(data->philo->id, "is thinking");
	time_since_last_meal = \
		(get_current_time() \
		- get_ms(data->philo->last_meal));
	think_time = \
		(data->args->time_to_die \
		- time_since_last_meal \
		- data->args->time_to_eat) \
		/ 2;
	if (think_time > 0)
		ft_sleep_ms(think_time);
}

void	go_to_sleep(t_data *data)
{
	print_timestamp(data->philo->id, "is sleeping");
	ft_sleep_ms(data->args->time_to_sleep);
}
