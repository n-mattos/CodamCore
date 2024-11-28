/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:51 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/25 12:58:55 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx-linux/mlx.h"
# include "mlx-linux/mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define T_CP t_complex
# define T_OFF t_offset
# define T_CL t_colour

# define TITLE "Noah's Fract-ol"
# define INSTRUCTIONS "Usage: ./fractol [window_size (0-2160)] [fractal (1-3)]\
 [iterations (>= 0)]\n\nFractals:\n1. Mandelbrot\n2.\
 Julia\n3. Burning Ship\n\nFor dynamic argument input, use:\n\
./fractol dynamic\n\n"

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define NEWTON 4

# define DEFAULT 0
# define MONOCHROME 1

# define MEMORY_ERROR "Memory allocation failed, exiting...\n"

# define PI 3.14159265358979323846

# define ERROR -1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

/*****************************************************************************\
* 								  Structures								  *
\*****************************************************************************/

/*	Image Data Struct
 *
 *	img:			pointer to the image struct
 *	addr:			pointer to the image data
 *	bits_per_pixel:	number of bits per pixel
 *	line_length:	number of bytes in a line
 *	endian:			endianess of the image data
 */
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

/*	Complex Number Struct
 *
 *	real:		real part of complex number
 *	imaginary:	imaginary part of complex number
 */
typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

/*	Image Offset Struct
 *
 *	x:	x offset
 *	y:	y offset
 */
typedef struct s_offset
{
	double	x;
	double	y;
}	t_offset;

/*	Colour Struct
 *
 */
typedef struct s_colour
{
	int	red;
	int	green;
	int	blue;
	int	mode;
}	t_colour;

/*	Data Struct
 *
 *	mlx:			pointer to the mlx struct
 *	win:			pointer to the window struct
 *	img:			image data struct
 *	max_iteration:	maximum number of iterations
 *	c:				complex number c
 *	z:				complex number z
 *	escape:			escape value
 *	zoom:			zoom value
 *	offset:			image offset
 *	width:			image width
 *	height:			image height
 *	colour:			image colour struct
 */
typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	int			set;
	int			julia_variant;
	int			max_iteration;
	t_complex	c;
	t_complex	z;
	double		zoom;
	t_offset	offset;
	int			width;
	int			height;
	t_colour	colour;
}	t_data;

/*****************************************************************************\
* 								Function prototypes							  *
\*****************************************************************************/

/* init.c   -   Initializer functions */
void	init_data(t_data *data);
T_CP	init_complex(double real, double imaginary);
T_OFF	init_offset(double x, double y);
T_CL	init_colour(int red, int green, int blue);

/* get_next_line */
char	*get_next_line(int fd);

/* get_next_line utils */
char	*ft_strcpy(char *dst, char *src);
char	*ft_realloc(char **original, size_t size);
char	*ft_strchr(const char *s, int c);
void	free_p(char **p);

/* parse_arguments.c   -   Parses any arguments from stdin */
void	parse_user_input(t_data *data);
void	get_resolution(t_data *data);
void	get_fractal_name(t_data *data);
void	get_iterations(t_data *data);
char	*get_argument(void);

/* parse_command_line.c   -   Parses any arguments from the command-line */
void	parse_command_line(t_data *data, char *argv[]);

/* hooks.c   -   Handles all keyboad / mouse inputs */
void	hooks(t_data *data);
int		mouse_handler(int button, int x, int y, t_data *data);
int		key_handler(int button, t_data *data);
int		close_window(t_data *data);
int		render(t_data *data);

/* hookfunctions.c */
void	change_offset(t_data *data, int button);
void	change_iteration(t_data *data, int button);
void	change_fractal(t_data *data, int button);
void	change_julia_variant(t_data *data);
void	reset_fractal(t_data *data);

/* print.c */
void	print_fractal_list(void);

/* draw.c   -   Refers the program to the right fractal, and draws it */
void	draw_fractal(t_data *data);
void	calculate_fractal(t_data *data, int x, int y);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);

/* colour.c   -   Calculates the necessary colour */
int		get_colour(t_data *data, int iteration);
void	change_colour(t_data *data);

/* mandelbrot.c */
void	draw_mandelbrot(t_data *d, int x, int y);

/* julia.c */
void	draw_julia(t_data *d, int x, int y);

/* burningship.c */
void	draw_burningship(t_data *d, int x, int y);

/* clean.c   -   Cleans up the program */
void	clean(t_data *data);

#endif
