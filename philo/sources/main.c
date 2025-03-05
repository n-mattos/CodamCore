/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:58:29 by nmattos           #+#    #+#             */
/*   Updated: 2025/03/05 14:34:40 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argc, argv);
	start_philos(&data);
	start_monitor(&data);
	cleanup(&data);
	return (0);
}
