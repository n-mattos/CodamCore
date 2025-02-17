/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:27:17 by nmattos-          #+#    #+#             */
/*   Updated: 2025/02/10 17:37:40 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	check_args_values(int argc, char *argv[]);
static bool	ft_isdigit(char c);

void	check_args(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		exit_error("wrong number of arguments");
	check_args_values(argc, argv);
}

static void	check_args_values(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				exit_error("arguments must only consist of digits");
			j++;
		}
		i++;
	}
}

static bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
