/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:31:16 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/12 12:39:34 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int filter = 0;
	for (const auto& level : levels) {
		if (argv[1] == level)
			break;
		filter++;
	}
	if (filter > 4)
		return (1);

	Harl karen;

	karen.complain(filter, "DEBUG");
	karen.complain(filter, "INFO");
	karen.complain(filter, "WARNING");
	karen.complain(filter, "ERROR");
	karen.complain(filter, "NONEXISTENT");
	return (0);
}
