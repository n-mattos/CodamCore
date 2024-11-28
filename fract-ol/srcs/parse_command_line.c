/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:58:14 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/25 09:18:03 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	parse_command_line(t_data *data, char *argv[])
{
	int	input;
	int	error;

	data->width = ft_atoi(argv[1], &error);
	if (data->width < 0 || data->width > 2160 || error == 1)
	{
		ft_printf("Invalid window size input\n");
		exit(0);
	}
	data->height = data->width;
	input = ft_atoi(argv[2], &error);
	ft_printf("%d\n", input);
	if (input < 1 || input > 3 || error == 1)
	{
		ft_printf("Invalid fractal input\n");
		exit(0);
	}
	data->set = input;
	data->max_iteration = ft_atoi(argv[3], &error);
	if (data->max_iteration < 0 || error == 1)
	{
		ft_printf("Invalid iterations input\n");
		exit(0);
	}
}
