/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:21:59 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/23 11:10:30 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// AMateria Class

AMateria::AMateria(std::string const& type) : _type(type) {
}

AMateria::~AMateria() {
}

std::string const& AMateria::getType() const {
	return (_type);
}

void	AMateria::use(ICharacter& target) {
	if (_type == "ice") {
		std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	} else if (_type == "cure") {
		std::cout << "* heals " << target.getName() << "'s wounds *\n";
	}
}


// Ice Class

AMateria* Ice::clone() const {
	return new Ice(*this);
}


// Cure Class

AMateria* Cure::clone() const {
	return new Cure(*this);
}
