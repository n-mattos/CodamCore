/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:44:13 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/23 10:22:57 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static bool	corpse_found(t_data *data);
static void	massacre(t_data *data);
static bool	finished_eating(t_data *data);

void	run_monitor(void *data)
{
	t_data	*data_ptr;

	data_ptr = (t_data *)data;
	ft_sleep_process_ms(data_ptr->n_philo / 3 + 15);
	if (data_ptr->max_meals == -1)
	{
		while (1)
		{
			if (corpse_found(data))
				return ;
			ft_sleep_process_ms(1);
		}
	}
	while (1)
	{
		if (corpse_found(data_ptr) || finished_eating(data_ptr))
			return ;
		ft_sleep_process_ms(1);
	}
}

static bool	corpse_found(t_data *data)
{
	int	i;
	int	delta_meal_time;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->philos[i].card);
		delta_meal_time = (get_current_time() - data->philos[i].last_meal);
		pthread_mutex_unlock(&data->philos[i].card);
		if (delta_meal_time > (int)data->die_time)
		{
			pthread_mutex_lock(&data->print_lock);
			printf("%ld\t%d %s\n", get_current_time() - data->start_time,
				data->philos[i].id, "died");
			massacre(data);
			pthread_mutex_unlock(&data->print_lock);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	finished_eating(t_data *data)
{
	if (data->max_meals == -1)
		return (false);
	pthread_mutex_lock(&data->meal_lock);
	if (data->full_philos >= data->max_meals)
	{
		pthread_mutex_unlock(&data->meal_lock);
		massacre(data);
		return (true);
	}
	pthread_mutex_unlock(&data->meal_lock);
	return (false);
}

static void	massacre(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->philos[i].card);
		data->philos[i].state = DEAD;
		pthread_mutex_unlock(&data->philos[i].card);
		i++;
	}
}
