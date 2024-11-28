/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:04:56 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/22 10:58:56 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(1);
	data->win = mlx_new_window(data->mlx, data->width, data->height, TITLE);
	if (data->win == NULL)
	{
		free(data->mlx);
		exit(1);
	}
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (data->set == JULIA)
		data->c = init_complex(-0.835, 0.2321);
	else
		data->c = init_complex(0.0, 0.0);
	data->julia_variant = 1;
	data->z = init_complex(0.0, 0.0);
	data->zoom = 1.0;
	data->offset = init_offset(0.0, 0.0);
	data->colour = init_colour(5, 10, 3);
}

t_complex	init_complex(double real, double imaginary)
{
	t_complex	complex;

	complex.r = real;
	complex.i = imaginary;
	return (complex);
}

t_offset	init_offset(double x, double y)
{
	t_offset	offset;

	offset.x = x;
	offset.y = y;
	return (offset);
}

t_colour	init_colour(int red, int green, int blue)
{
	t_colour	colour;

	colour.red = red;
	colour.green = green;
	colour.blue = blue;
	colour.mode = DEFAULT;
	return (colour);
}
