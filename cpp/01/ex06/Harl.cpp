/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:31:02 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/16 17:08:08 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << DEBUG << std::endl;
}

void	Harl::info(void) {
	std::cout << INFO << std::endl;
}

void	Harl::warning(void) {
	std::cout << WARNING << std::endl;
}

void	Harl::error(void) {
	std::cout << ERROR << std::endl;
}

static void	print_usage(std::string level) {
	std::cout << "Level does not exist: " << level << std::endl
			  << "Use; DEBUG, INFO, WARNING, ERROR."<< std::endl;
}

void	Harl::complain(std::string level) {
	std::string levels[] =
		{"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	if (i < 4)
		(this->*functions[i])();
	else
		print_usage(level);
}
