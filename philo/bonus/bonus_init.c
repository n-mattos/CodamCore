/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:41:02 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 16:56:08 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

static void		init_semaphores(t_data *data);
static t_philo	*allocate_philos(t_data *data);

void	init_data(t_data *data, int argc, char *argv[])
{
	data->n_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->start = false;
	data->max_meals = -1;
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	data->corpse = false;
	init_semaphores(data);
}

void	start_philos(t_data *data)
{
	int	i;

	(*data).philos = allocate_philos(data);
	i = 0;
	while (i < data->n_philo)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == 0)
		{
			data->philos[i].id = i;
			data->philos[i].total_meals = 0;
			data->philos[i].data = data;
			data->philos[i].last_meal = get_current_time();
			pthread_create(&data->philos[i].monitor, NULL, &child_monitor, \
				&data->philos[i]);
			philo_life(&data->philos[i]);
			pthread_join(data->philos[i].monitor, NULL);
			exit(0);
		}
		i++;
	}
	sem_wait(data->time_lock);
	data->start = true;
	sem_post(data->time_lock);
	ft_sleep_ms(10);
	// sem_wait(data->exit);
	// sem_post(data->exit);
	i = 0;
	while (i < data->n_philo)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		i++;
	}
}

static void	init_semaphores(t_data *data)
{
	sem_unlink("/forks");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->n_philo);
	sem_unlink("/time");
	data->time_lock = sem_open("/time", O_CREAT, 0644, 1);
	sem_unlink("/meal");
	data->meal_lock = sem_open("/meal", O_CREAT, 0644, 1);
	sem_unlink("/death");
	data->death_lock = sem_open("/death", O_CREAT, 0644, 1);
	sem_unlink("/exit");
	data->exit = sem_open("/exit", O_CREAT, 0644, data->n_philo);
}

static t_philo	*allocate_philos(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philos)
		exit_error("malloc failed");
	return (data->philos);
}
