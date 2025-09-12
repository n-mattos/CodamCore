/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:31:02 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/12 15:23:17 by nmattos-         ###   ########.fr       */
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

void	Harl::complain(int filter, std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int msg = 0;
	while (msg < 4 && levels[msg] != level)
		msg++;
	if (msg >= 0 && filter <= msg)
	{
        switch (msg) {
            case 0:
                if (filter <= 0) this->debug();
                break;
            case 1:
                if (filter <= 1) this->info();
                break;
            case 2:
                if (filter <= 2) this->warning();
                break;
            case 3:
                if (filter <= 3) this->error();
                break;
			default:
				print_usage(level);
        }
	}
}
