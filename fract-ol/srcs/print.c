/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:22:08 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/22 11:17:42 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_fractal_list(void)
{
	ft_printf("Choose a fractal to draw (1-3):\n");
	ft_printf("1. Mandelbrot\n");
	ft_printf("2. Julia\n");
	ft_printf("3. Burning Ship\n");
	ft_printf(">> ");
}
