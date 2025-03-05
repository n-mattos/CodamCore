/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:44:50 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/04 14:20:42 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

static bool		is_starving(int time_to_die, t_philo *philo);
static void		*check_for_bodies(void *args);
static void		*check_stomach(void *args);

void	*child_monitor(void *data)
{
	t_data	*info;

	info = (t_data *)data;
	while (1)
	{
		if (is_starving(info->args->time_to_die, info->philo))
		{
			die(info->philo->id);
			info->philo->state = DEAD;
			sem_post(info->args->stop);
			return (NULL);
		}
		ft_sleep_ms(1);
	}
}

void	stop_threads(t_args *args, pid_t *pids, pthread_t *threads)
{
	pthread_t	death_thread;
	pthread_t	full_thread;

	sem_unlink("/exit");
	args->exit = sem_open("/exit", O_CREAT, 0644, 0);
	if (args->exit == SEM_FAILED)
		exit_error_free("sem_open failed", pids, threads, args);
	pthread_create(&death_thread, NULL, &check_for_bodies, args);
	pthread_create(&full_thread, NULL, &check_stomach, args);
	ft_sleep_ms(50);
	sem_wait(args->exit);
	pthread_detach(death_thread);
	pthread_detach(full_thread);
}

static bool	is_starving(int time_to_die, t_philo *philo)
{
	if (get_current_time() - get_ms(philo->last_meal)
		> (size_t)time_to_die)
		return (true);
	return (false);
}

static void	*check_for_bodies(void *args)
{
	t_args	*arg;

	arg = (t_args *)args;
	ft_sleep_ms(5);
	sem_wait(arg->stop);
	sem_post(arg->exit);
	return (NULL);
}

static void	*check_stomach(void *args)
{
	t_args	*arg;

	arg = (t_args *)args;
	if (arg->number_of_times_each_philosopher_must_eat == -1)
		return (NULL);
	ft_sleep_ms(5);
	while (arg->full_philos < arg->number_of_philosophers)
	{
		sem_wait(arg->full);
		arg->full_philos++;
	}
	sem_post(arg->exit);
	return (NULL);
}
