/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:33:23 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/22 10:57:53 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	parse_user_input(t_data *data)
{
	get_resolution(data);
	get_fractal_name(data);
	get_iterations(data);
}

void	get_resolution(t_data *data)
{
	char	*input;
	int		error;

	ft_printf("Enter the application size (0 - 2160)\n>> ");
	input = get_argument();
	error = 1;
	data->width = ft_atoi(input, &error);
	data->height = data->width;
	free(input);
	if (error == 1 || data->width <= 0 || data->width > 2160)
	{
		ft_printf("Invalid input, please enter a positive number.\n\n");
		get_resolution(data);
		return ;
	}
	ft_printf("Resolution set to %d x %d\n\n", data->width, data->height);
}

void	get_fractal_name(t_data *data)
{
	char	*input;
	int		error;

	print_fractal_list();
	input = get_argument();
	error = 1;
	data->set = ft_atoi(input, &error);
	free(input);
	if (error == 1)
	{
		ft_printf("Invalid input, try again.\n\n");
		get_fractal_name(data);
		return ;
	}
	if (data->set <= 0 || data->set > 3)
	{
		ft_printf("Invalid fractal, try again.\n\n");
		get_fractal_name(data);
		return ;
	}
	ft_printf("Fractal number %d chosen.\n\n", data->set);
}

void	get_iterations(t_data *data)
{
	char	*input;
	int		error;

	ft_printf("Enter the number of iterations\n>> ");
	input = get_argument();
	error = 1;
	data->max_iteration = ft_atoi(input, &error);
	free(input);
	if (error == 1 || data->max_iteration <= 0)
	{
		ft_printf("Invalid input, please enter a positive number.\n\n");
		get_iterations(data);
		return ;
	}
	ft_printf("Max iterations set to %d\n", data->max_iteration);
}

char	*get_argument(void)
{
	char	*argument;

	argument = get_next_line(0);
	if (!argument)
	{
		perror(MEMORY_ERROR);
		exit(ERROR);
	}
	argument[ft_strlen(argument) - 1] = '\0';
	return (argument);
}
