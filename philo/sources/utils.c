/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:45:15 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/23 10:24:59 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(const char *nptr)
{
	long int	sum;

	sum = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		sum = (sum * 10) + (*(nptr++) - 48);
		if (sum > INT_MAX)
			return (-1);
	}
	return (sum);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_sleep_ms(t_philo *p, size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		if (check_death(p))
			return (STOP);
		usleep(100);
	}
	return (CONTINUE);
}

void	ft_sleep_process_ms(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(100);
}

void	print_timestamp(t_philo *p, char *message)
{
	pthread_mutex_lock(&p->data->print_lock);
	if (check_death(p))
	{
		pthread_mutex_unlock(&p->data->print_lock);
		return ;
	}
	printf("%ld\t%d %s\n",
		get_current_time() - p->data->start_time, p->id, message);
	pthread_mutex_unlock(&p->data->print_lock);
}
