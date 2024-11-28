/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:18 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/21 12:36:42 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_colour(t_data *data, int iteration)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (data->colour.mode == MONOCHROME)
	{
		if (iteration % 2)
			return (0x000000);
		else
			return (0xFFFFFF);
	}
	t = (double)iteration / data->max_iteration;
	r = (int)(data->colour.red * (1 - t) * t * t * t * 255);
	g = (int)(data->colour.green * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(data->colour.blue * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	change_colour(t_data *data)
{
	data->colour.red = (data->colour.red + 5) % 256;
	data->colour.green = (data->colour.green + 7) % 256;
	data->colour.blue = (data->colour.blue + 3) % 32;
}
