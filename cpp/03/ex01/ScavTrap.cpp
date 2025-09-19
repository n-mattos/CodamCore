/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:11:36 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 10:45:49 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "<ScavTrap> Default Constructor called" << std::endl;
	_name = "Grunt";
	_hp = 100;
	_ep = 50;
	_at = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "<ScavTrap> Parameterized Constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 50;
	_at = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "<ScavTrap> Deconstructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (_ep <= 0) {
		std::cout
			<< "ScavTrap "
			<< _name
			<< " is out of energy!"
		<< std::endl;
		return;
	}

	_ep -= 1;
	std::cout
		<< "ScavTrap "
		<< _name
		<< " attacks "
		<< target
		<< ", causing "
		<< _at
		<< " points of damage!"
	<< std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	_hp -= amount;
	if (_hp < 0) {
		amount += _hp;
		_hp = 0;
	}

	std::cout
		<< "ScavTrap "
		<< _name
		<< " lost "
		<< amount
		<< " health! | HP: "
		<< _hp
	<< std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout
			<< "ScavTrap "
			<< _name
			<< " is out of energy!"
		<< std::endl;
		return;
	}

	_hp += amount;	// no mention of max hp in subject, so let it go over 10
	_ep -= 1;
	std::cout
		<< "ScavTrap "
		<< _name
		<< " used 1 EP to repair itself for "
		<< amount
		<< " health! | HP: "
		<< _hp
		<< " | EP: "
		<< _ep
	<< std::endl;
}

void ScavTrap::guardGate() {
	std::cout
		<< "ScavTrap "
		<< _name
		<< " is now in Gatekeeper Mode."
	<< std::endl;
}
