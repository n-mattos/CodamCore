/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:44:13 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/11 11:42:26 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static bool	corpse_found(t_data *data);
static bool	finished_eating(t_data *data);
static void	*run_monitor(void *data);

void	start_monitor(t_data *data)
{
	pthread_create(&data->monitor, NULL, &run_monitor, data);
}

static void	*run_monitor(void *data)
{
	t_data	*data_ptr;
	int		i;

	data_ptr = (t_data *)data;
	i = 0;
	ft_sleep_ms(data_ptr->n_philo / 3 + 15);
	while (1)
	{
		if (corpse_found(data) || finished_eating(data))
			break ;
		ft_sleep_ms(1);
	}
	return (NULL);
}

static bool	corpse_found(t_data *data)
{
	int	i;
	int	delta_meal_time;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->meal_lock);
		delta_meal_time = (get_current_time() - data->philos[i].last_meal);
		pthread_mutex_unlock(&data->meal_lock);
		if (delta_meal_time > (int)data->die_time)
		{
			pthread_mutex_lock(&data->death_lock);
			if (data->corpse == false)
			{
				data->corpse = true;
				print_timestamp(data->philos[i].id, "died");
			}
			pthread_mutex_unlock(&data->death_lock);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	finished_eating(t_data *data)
{
	int	i;

	i = 0;
	if (data->max_meals == -1)
		return (false);
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (data->philos[i].total_meals < data->max_meals)
		{
			pthread_mutex_unlock(&data->meal_lock);
			return (false);
		}
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	pthread_mutex_lock(&data->death_lock);
	if (data->corpse == false)
		data->corpse = true;
	pthread_mutex_unlock(&data->death_lock);
	return (true);
}
