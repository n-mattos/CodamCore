/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:17 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/03 16:38:21 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philosophers.h"

void	print_timestamp(int id, char *message)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%.3ld %d %s\n", time.tv_usec / 1000, id, message);
}

void	exit_error(char *message)
{
	printf("Error: %s\n", message);
	exit(1);
}
