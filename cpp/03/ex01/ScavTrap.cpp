/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:11:36 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 11:09:40 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "<ScavTrap> Default Constructor called" << std::endl;
	this->name = "Grunt";
	this->hp = 100;
	this->ep = 50;
	this->at = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "<ScavTrap> Parameterized Constructor called" << std::endl;
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->at = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "<ScavTrap> Deconstructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout
		<< "ScavTrap "
		<< this->name
		<< " attacks "
		<< target
		<< ", causing "
		<< this->at
		<< " points of damage!"
	<< std::endl;
}
void	ScavTrap::takeDamage(unsigned int amount) {
	this->hp -= amount;
	if (this->hp < 0)
		this->hp = 0;
	std::cout
		<< "ScavTrap "
		<< this->name
		<< " lost "
		<< amount
		<< " health! | HP: "
		<< this->hp
	<< std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	this->ep -= 1;
	if (this->ep < 0)
		this->ep = 0;
	std::cout
		<< "ScavTrap "
		<< this->name
		<< " used 1 EP to repair itself for "
		<< amount
		<< " health! | EP: "
		<< this->ep
	<< std::endl;
}

void ScavTrap::guardGate() {
	std::cout
		<< "ScavTrap "
		<< this->name
		<< " is now in Gatekeeper Mode."
	<< std::endl;
}
