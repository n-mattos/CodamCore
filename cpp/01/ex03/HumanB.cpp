/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:02:09 by nmattos           #+#    #+#             */
/*   Updated: 2025/08/11 13:22:34 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB() {
	// std::cout << this->getName() << " has fled." << std::endl;
}

HumanB::HumanB(std::string name) {
	this->name = name;
}

std::string	HumanB::getName(void) const {
	return (this->name);
}

std::string	HumanB::getWeapon(void) const {
	return (this->weapon->getType());
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack(void) {
	if (weapon) {
		std::cout << this->getName() << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << this->getName() << " has no weapon to attack with!" << std::endl;
	}
}