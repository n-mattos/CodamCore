/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:44:33 by nmattos           #+#    #+#             */
/*   Updated: 2025/08/11 13:20:56 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	this->type = "";
}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {
	// std::cout << this->getType() << " ran out of durability." << std::endl;
}

std::string	Weapon::getType(void) const {
	return (this->type);
}

void Weapon::setType(std::string type) {
	this->type = type;
}
