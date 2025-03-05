/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 16:34:20 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/02/27 12:33:26 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	routine(t_data *data);
static int	check_morgue(t_data *data);

void	*philosopher_life(void *data_void)
{
	t_data	*data;

	data = (t_data *)data_void;
	pthread_mutex_lock(&(data)->args->full_philos[data->philo->id]);
	if (data->philo->id % 2 == 0)
		ft_sleep_ms(data->args->time_to_eat * 0.9 + 1);
	while (data->philo->state == ALIVE || data->philo->state == FULL)
	{
		routine(data);
	}
	pthread_mutex_unlock(&(data)->args->full_philos[data->philo->id]);
	return (NULL);
}

static void	routine(t_data *data)
{
	if ((data->philo->state == ALIVE || data->philo->state == FULL)
		&& take_forks(data))
	{
		eat(data);
		return_forks(data);
		check_morgue(data);
		if (data->philo->state == DEAD || data->philo->state == ESCAPE)
		{
			return ;
		}
		go_to_sleep(data);
		if (data->philo->state == ESCAPE || check_morgue(data) == ESCAPE)
			return ;
		think(data);
	}
	else
	{
		if (check_morgue(data) == ESCAPE)
			return ;
		ft_sleep_ms(1);
	}
}

static int	check_morgue(t_data *data)
{
	is_starving(data);
	pthread_mutex_lock(data->args->morgue);
	if (*(data)->args->escape)
	{
		pthread_mutex_unlock(data->args->morgue);
		data->philo->state = ESCAPE;
		return (ESCAPE);
	}
	pthread_mutex_unlock(data->args->morgue);
	return (0);
}
