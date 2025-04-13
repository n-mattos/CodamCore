/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 16:58:00 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/13 17:21:22 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA() {
	// std::cout << this->getName() << " has fled." << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) {
	this->name = name;
	this->weapon = &weapon;
}

void HumanA::attack(void) {
	std::cout	<< this->getName() << " attacks with their "
				<< this->getWeapon() << std::endl;
}