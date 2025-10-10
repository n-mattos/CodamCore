/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:38:36 by nmattos           #+#    #+#             */
/*   Updated: 2025/10/10 12:55:16 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Grunt") {
	std::cout << "Default Constructor called" << "\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "Parameterized Constructor called" << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy Constructor called" << "\n";
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called" << "\n";
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_at = other._at;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Deconstructor called" << "\n";
}

void	ClapTrap::attack(const std::string& target) {
	if (_ep <= 0) {
		std::cout
			<< "ClapTrap "
			<< _name
			<< " is out of energy!"
		<< "\n";
		return;
	}
	if (_hp <= 0) {
		std::cout
			<< "ClapTrap "
			<< _name
			<< " is dead!"
		<< "\n";
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
	<< "\n";
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
	<< "\n";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout
			<< "ClapTrap "
			<< _name
			<< " is out of energy!"
		<< "\n";
		return;
	}
	if (_hp <= 0) {
		std::cout
			<< "ClapTrap "
			<< _name
			<< " is dead!"
		<< "\n";
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
	<< "\n";
}
