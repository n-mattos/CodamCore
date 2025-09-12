/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:02:09 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/12 15:14:42 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB() {
	// std::cout << this->getName() << " has fled." << std::endl;
}

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {
}

std::string	HumanB::getName() const {
	return (name);
}

std::string	HumanB::getWeapon() const {
	return (weapon ? weapon->getType() : nullptr);
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if (weapon) {
		std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << getName() << " has no weapon to attack with!" << std::endl;
	}
}