/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:55:59 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/21 12:27:31 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	change_offset(t_data *data, int button)
{
	if (button == XK_Left)
		data->offset.x -= 0.1 * data->zoom;
	else if (button == XK_Right)
		data->offset.x += 0.1 * data->zoom;
	else if (button == XK_Up)
		data->offset.y -= 0.1 * data->zoom;
	else if (button == XK_Down)
		data->offset.y += 0.1 * data->zoom;
}

void	change_iteration(t_data *data, int button)
{
	if (button == XK_equal)
		data->max_iteration += 10;
	else if (button == XK_minus)
	{
		if (data->max_iteration > 10)
			data->max_iteration -= 10;
		else
			data->max_iteration = 0;
	}
}

void	change_fractal(t_data *data, int button)
{
	if (button == XK_s)
	{
		data->zoom = 1.0;
		data->offset = init_offset(0.0, 0.0);
		data->set = (data->set % 3) + 1;
		if (data->set == JULIA)
			data->c = init_complex(-0.835, 0.2321);
	}
	else if (button == XK_c)
		change_colour(data);
	else if (button == XK_m)
		data->colour.mode = (data->colour.mode % 2) + 1;
	else if (button == XK_j)
		change_julia_variant(data);
}

void	change_julia_variant(t_data *data)
{
	data->set = JULIA;
	data->julia_variant = (data->julia_variant % 10) + 1;
	if (data->julia_variant == 1)
		data->c = init_complex(0.285, 0.0);
	else if (data->julia_variant == 2)
		data->c = init_complex(0.285, 0.01);
	else if (data->julia_variant == 3)
		data->c = init_complex(0.45, 0.1428);
	else if (data->julia_variant == 4)
		data->c = init_complex(-0.70176, -0.3842);
	else if (data->julia_variant == 5)
		data->c = init_complex(-0.835, 0.2321);
	else if (data->julia_variant == 6)
		data->c = init_complex(-0.8, 0.156);
	else if (data->julia_variant == 7)
		data->c = init_complex(-0.7269, 0.1889);
	else if (data->julia_variant == 8)
		data->c = init_complex(0, 0.8);
	else if (data->julia_variant == 9)
		data->c = init_complex(0.35, 0.35);
	else if (data->julia_variant == 10)
		data->c = init_complex(0.4, 0.4);
}

void	reset_fractal(t_data *data)
{
	data->zoom = 1.0;
	data->offset = init_offset(0.0, 0.0);
}
