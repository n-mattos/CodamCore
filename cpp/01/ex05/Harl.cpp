/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:22:10 by nmattos-          #+#    #+#             */
/*   Updated: 2025/08/11 13:26:28 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

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
