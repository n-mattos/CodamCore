/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:51:23 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/11 15:19:53 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	die(t_data *data)
{
	pthread_mutex_lock(data->args->morgue);
	if (*(data)->args->escape == true)
	{
		pthread_mutex_unlock(data->args->morgue);
		return ;
	}
	print_timestamp(data->philo->id, "died");
	*(data)->args->escape = true;
	pthread_mutex_unlock(data->args->morgue);
	data->philo->state = DEAD;
}

void	eat(t_data *data)
{
	if (is_starving(data))
		return ;
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
			pthread_mutex_unlock(&(data)->args->full_philos[data->philo->id]);
		}
	}
	ft_sleep_ms(data->args->time_to_eat);
}

bool	is_starving(t_data *data)
{
	int	time_since_last_meal;

	time_since_last_meal = \
		(get_current_time() \
		- get_ms(data->philo->last_meal));
	if (time_since_last_meal > data->args->time_to_die)
	{
		die(data);
		return (true);
	}
	return (false);
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
