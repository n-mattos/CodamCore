/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:58:42 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/22 10:57:15 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_fractal(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			calculate_fractal(data, x, y);
			x++;
		}
		y++;
	}
}

void	calculate_fractal(t_data *data, int x, int y)
{
	if (data->set == MANDELBROT)
		draw_mandelbrot(data, x, y);
	else if (data->set == JULIA)
		draw_julia(data, x, y);
	else if (data->set == BURNINGSHIP)
		draw_burningship(data, x, y);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)(dst) = color;
}
