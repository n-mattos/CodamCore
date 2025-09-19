/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:34:25 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 12:04:28 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "<DiamondTrap> Default Constructor called" << std::endl;
	_name = "Grunt";
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_at = FragTrap::_at;
}

DiamondTrap::DiamondTrap(std::string name) {
	std::cout << "<DiamondTrap> Parameterized Constructor called" << std::endl;
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_at = FragTrap::_at;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "<DiamondTrap> Deconstructor called" << std::endl;
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
	<< std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout
			<< "DiamondTrap "
			<< _name
			<< " is out of energy!"
		<< std::endl;
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
	<< std::endl;
}

void 	DiamondTrap::whoAmI(void) {
	std::cout
		<< "My DiamondTrap name is: "
		<< _name
		<< ", and my ClapTrap name is: "
		<< ClapTrap::_name
		<< "."
	<< std::endl;
}
