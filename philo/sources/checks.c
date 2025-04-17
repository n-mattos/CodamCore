/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 12:27:17 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/04/17 11:03:43 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static bool	ft_isdigit(char c);

int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
	{
		printf("wrong number of arguments");
		return (FAIL);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("arguments must only consist of digits");
				return (FAIL);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
