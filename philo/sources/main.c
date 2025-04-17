/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 12:58:29 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/17 15:20:08 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_args(argc, argv) == FAIL)
		return (1);
	if (init_data(&data, argc, argv) == FAIL)
		return (1);
	if (start_philos(&data) == FAIL)
	{
		cleanup(&data);
		return (1);
	}
	run_monitor(&data);
	cleanup(&data);
	return (0);
}
