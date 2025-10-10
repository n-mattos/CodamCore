/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:11:36 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 12:55:53 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "<ScavTrap> Default Constructor called" << "\n";
	_name = "Grunt";
	_hp = 100;
	_ep = 50;
	_at = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "<ScavTrap> Parameterized Constructor called" << "\n";
	_name = name;
	_hp = 100;
	_ep = 50;
	_at = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "<ScavTrap> Copy Constructor called" << "\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "<ScavTrap> Copy Assignment Operator called" << "\n";
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_at = other._at;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "<ScavTrap> Deconstructor called" << "\n";
}

void	ScavTrap::attack(const std::string& target) {
	if (_ep <= 0) {
		std::cout
			<< "ScavTrap "
			<< _name
			<< " is out of energy!"
		<< "\n";
		return;
	}
	if (_hp <= 0) {
		std::cout
			<< "ScavTrap "
			<< _name
			<< " is dead!"
		<< "\n";
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
	<< "\n";
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
	<< "\n";
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout
			<< "ScavTrap "
			<< _name
			<< " is out of energy!"
		<< "\n";
		return;
	}
	if (_hp <= 0) {
		std::cout
			<< "ScavTrap "
			<< _name
			<< " is dead!"
		<< "\n";
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
	<< "\n";
}

void ScavTrap::guardGate() {
	if (_hp <= 0) {
		std::cout
			<< "ScavTrap "
			<< _name
			<< " is dead!"
		<< "\n";
		return;
	}

	std::cout
		<< "ScavTrap "
		<< _name
		<< " is now in Gatekeeper Mode."
	<< "\n";
}
