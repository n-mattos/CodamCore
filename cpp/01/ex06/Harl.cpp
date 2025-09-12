/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:31:02 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/12 12:45:42 by nmattos-         ###   ########.fr       */
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

	int i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	if (i >= 0 && filter <= i)
	{
        switch (i) {
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
        }
    } else if (i == -1)
        print_usage(level);
}
