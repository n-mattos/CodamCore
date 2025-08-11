/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:58:00 by nmattos           #+#    #+#             */
/*   Updated: 2025/08/11 13:23:31 by nmattos-         ###   ########.fr       */
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

std::string	HumanA::getName(void) const {
	return (this->name);
}

std::string	HumanA::getWeapon(void) const {
	return (this->weapon->getType());
}

void HumanA::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanA::attack(void) {
	std::cout	<< this->getName() << " attacks with their "
				<< this->getWeapon() << std::endl;
}