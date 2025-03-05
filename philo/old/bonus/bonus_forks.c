/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:41:11 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/03 17:25:13 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

bool	take_forks(sem_t **forks)
{
	if (sem_wait((*forks)) == -1)
		return (false);
	if (sem_wait((*forks)) == -1)
	{
		sem_post((*forks));
		return (false);
	}
	return (true);
}

void	return_forks(sem_t **forks)
{
	sem_post((*forks));
	sem_post((*forks));
}
