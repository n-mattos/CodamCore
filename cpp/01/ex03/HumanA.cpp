/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:58:00 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/12 15:14:29 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA() {
	// std::cout << this->getName() << " has fled." << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(&weapon) {
}

std::string	HumanA::getName() const {
	return (name);
}

std::string	HumanA::getWeapon() const {
	return (weapon->getType());
}

void HumanA::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanA::attack(void) {
	std::cout	<< getName() << " attacks with their "
				<< getWeapon() << std::endl;
}