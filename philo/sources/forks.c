/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:38:21 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/11 14:54:47 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// static bool	forks_available(t_data *data);

bool	take_forks(t_data *data)
{
	// if (forks_available(data) == false)
	// 	return (false);
	// pthread_mutex_lock(data->forks->grab);
	if (data->philo->left_fork > data->philo->right_fork)
	{
		pthread_mutex_lock(&data->forks->mutexes[data->philo->right_fork]);
		pthread_mutex_lock(&data->forks->mutexes[data->philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&data->forks->mutexes[data->philo->left_fork]);
		pthread_mutex_lock(&data->forks->mutexes[data->philo->right_fork]);
	}
	// data->forks->available[data->philo->left_fork] = false;
	// data->forks->available[data->philo->right_fork] = false;
	// pthread_mutex_unlock(data->forks->grab);
	return (true);
}

void	return_forks(t_data *data)
{
	// pthread_mutex_lock(data->forks->grab);
	if (data->philo->left_fork > data->philo->right_fork)
	{
		pthread_mutex_unlock(&data->forks->mutexes[data->philo->right_fork]);
		pthread_mutex_unlock(&data->forks->mutexes[data->philo->left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&data->forks->mutexes[data->philo->left_fork]);
		pthread_mutex_unlock(&data->forks->mutexes[data->philo->right_fork]);
	}
	// data->forks->available[data->philo->left_fork] = true;
	// data->forks->available[data->philo->right_fork] = true;
	// pthread_mutex_unlock(data->forks->grab);
}

// static bool	forks_available(t_data *data)
// {
// 	bool	available;

// 	pthread_mutex_lock(data->forks->grab);
// 	if (data->args->number_of_philosophers == 1)
// 	{
// 		pthread_mutex_unlock(data->forks->grab);
// 		return (false);
// 	}
// 	available = data->forks->available[data->philo->left_fork] && data->forks->available[data->philo->right_fork];
// 	pthread_mutex_unlock(data->forks->grab);
// 	return (available);
// }
