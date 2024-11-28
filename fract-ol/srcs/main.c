/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:01:15 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/22 11:10:43 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2 && ft_strncmp(argv[1], "dynamic", 8) == 0)
		parse_user_input(&data);
	else if (argc == 4)
		parse_command_line(&data, argv);
	else
	{
		ft_printf(INSTRUCTIONS);
		return (0);
	}
	init_data(&data);
	render(&data);
	hooks(&data);
	return (0);
}
