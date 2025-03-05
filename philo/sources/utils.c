/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:45:15 by nmattos-          #+#    #+#             */
/*   Updated: 2025/03/05 14:28:58 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(const char *nptr)
{
	long int	sum;
	int			sign;

	sum = 0;
	sign = 1;
	if ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		return (0);
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9' && sum < 2147483648)
		sum = (sum * 10) + (*(nptr++) - 48);
	if (sign == -1)
		if (sum > 2147483648)
			return (0);
	if (sign != -1)
		if (sum > 2147483647)
			return (0);
	if (*nptr != '\0')
		return (0);
	return (sum * sign);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep_ms(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(100);
}

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
