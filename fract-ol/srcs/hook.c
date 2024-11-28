/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:07:41 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/21 12:22:37 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	hooks(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_handler, data);
	mlx_hook(data->win, 2, 1L << 0, key_handler, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
}

int	mouse_handler(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		data->zoom /= 1.3;
		data->offset.x += (x - data->width / 2) * 0.005 * data->zoom;
		data->offset.y += (y - data->height / 2) * 0.005 * data->zoom;
	}
	else if (button == 5)
	{
		data->zoom *= 1.3;
		data->offset.x -= (x - data->width / 2) * 0.005 * data->zoom;
		data->offset.y -= (y - data->height / 2) * 0.005 * data->zoom;
	}
	return (0);
}

int	key_handler(int button, t_data *data)
{
	if (button == XK_Escape)
		close_window(data);
	else if (button == XK_s || button == XK_c
		|| button == XK_m || button == XK_j)
		change_fractal(data, button);
	else if (button == XK_r)
		reset_fractal(data);
	else if (button == XK_Left || button == XK_Right
		|| button == XK_Up || button == XK_Down)
		change_offset(data, button);
	else if (button == XK_equal || button == XK_minus)
		change_iteration(data, button);
	return (0);
}

int	close_window(t_data *data)
{
	clean(data);
	return (0);
}

int	render(t_data *data)
{
	draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
