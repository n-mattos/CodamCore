/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:38:36 by nmattos           #+#    #+#             */
/*   Updated: 2025/10/07 11:03:18 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Grunt") {
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "Parameterized Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_at = other._at;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Deconstructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_ep <= 0) {
		std::cout
			<< "ClapTrap "
			<< _name
			<< " is out of energy!"
		<< std::endl;
		return;
	}

	_ep -= 1;
	std::cout
		<< "ClapTrap "
		<< _name
		<< " attacks "
		<< target
		<< ", causing "
		<< _at
		<< " points of damage!"
	<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	_hp -= amount;
	if (_hp < 0) {
		amount += _hp;
		_hp = 0;
	}

	std::cout
		<< "ClapTrap "
		<< _name
		<< " lost "
		<< amount
		<< " health! | HP: "
		<< _hp
	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout
			<< "ClapTrap "
			<< _name
			<< " is out of energy!"
		<< std::endl;
		return;
	}

	_hp += amount;	// no mention of max hp in subject, so let it go over 10
	_ep -= 1;
	std::cout
		<< "ClapTrap "
		<< _name
		<< " used 1 EP to repair itself for "
		<< amount
		<< " health! | HP: "
		<< _hp
		<< " | EP: "
		<< _ep
	<< std::endl;
}
