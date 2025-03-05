/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 16:38:21 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/02/27 12:32:09 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	take_forks(t_data *data)
{
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
	return (true);
}

void	return_forks(t_data *data)
{
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
}
