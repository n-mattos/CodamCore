/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:34:25 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 12:57:58 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "<DiamondTrap> Default Constructor called" << "\n";
	_name = "Grunt";
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_at = FragTrap::_at;
}

DiamondTrap::DiamondTrap(std::string name) {
	std::cout << "<DiamondTrap> Parameterized Constructor called" << "\n";
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_at = FragTrap::_at;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	std::cout << "<DiamondTrap> Copy Constructor called" << "\n";
	_name = other._name;
	ClapTrap::_name = other.ClapTrap::_name;
	_hp = other._hp;
	_ep = other._ep;
	_at = other._at;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "<DiamondTrap> Copy Assignment Operator called" << "\n";
	if (this != &other) {
		_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name;
		_hp = other._hp;
		_ep = other._ep;
		_at = other._at;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "<DiamondTrap> Deconstructor called" << "\n";
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount) {
	_hp -= amount;
	if (_hp < 0) {
		amount += _hp;
		_hp = 0;
	}

	std::cout
		<< "DiamondTrap "
		<< _name
		<< " lost "
		<< amount
		<< " health! | HP: "
		<< _hp
	<< "\n";
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout
			<< "DiamondTrap "
			<< _name
			<< " is out of energy!"
		<< "\n";
		return;
	}
	if (_hp <= 0) {
		std::cout
			<< "DiamondTrap "
			<< _name
			<< " is dead!"
		<< "\n";
		return;
	}

	_hp += amount;	// no mention of max hp in subject, so let it go over 10
	_ep -= 1;
	std::cout
		<< "DiamondTrap "
		<< _name
		<< " used 1 EP to repair itself for "
		<< amount
		<< " health! | HP: "
		<< _hp
		<< " | EP: "
		<< _ep
	<< "\n";
}

void 	DiamondTrap::whoAmI(void) {
	if (_hp <= 0) {
		std::cout
			<< "DiamondTrap "
			<< _name
			<< " is dead!"
		<< "\n";
		return;
	}

	std::cout
		<< "My DiamondTrap name is: "
		<< _name
		<< ", and my ClapTrap name is: "
		<< ClapTrap::_name
		<< "."
	<< "\n";
}
