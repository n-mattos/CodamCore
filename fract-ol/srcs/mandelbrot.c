/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:58:04 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/21 10:49:41 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandelbrot(t_data *d, int x, int y)
{
	int		iteration;
	double	temp;

	d->c.r = (4 * x / (double)d->width - 2) * d->zoom + d->offset.x;
	d->c.i = (4 * y / (double)d->height - 2) * d->zoom + d->offset.y;
	d->z.r = 0.0;
	d->z.i = 0.0;
	iteration = 0;
	while ((d->z.r * d->z.r) + (d->z.i * d->z.i) < 4
		&& iteration < d->max_iteration)
	{
		temp = (d->z.r * d->z.r) - (d->z.i * d->z.i) + d->c.r;
		d->z.i = 2 * (d->z.r * d->z.i) + d->c.i;
		d->z.r = temp;
		iteration++;
	}
	my_mlx_pixel_put(&d->img, x, y, get_colour(d, iteration));
}
