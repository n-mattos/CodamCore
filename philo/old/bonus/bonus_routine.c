/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:21:47 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/04 11:47:01 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

static void	routine(t_data *data);
static void	lonely_routine(t_data *data);

void	philosopher_life(t_data *data)
{
	while (data->philo->state != DEAD)
	{
		if (data->args->number_of_philosophers == 1)
			lonely_routine(data);
		else
			routine(data);
	}
}

static void	routine(t_data *data)
{
	if (data->philo->state != DEAD)
	{
		take_forks(&(data->args->forks));
		eat(data);
		return_forks(&(data->args->forks));
		go_to_sleep(data);
		think(data);
	}
}

static void	lonely_routine(t_data *data)
{
	if (data->philo->state != DEAD)
	{
		print_timestamp(data->philo->id, "is thinking");
		go_to_sleep(data);
		data->philo->state = DEAD;
	}
}
