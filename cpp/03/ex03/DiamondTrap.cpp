/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:34:25 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 14:44:05 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "<DiamondTrap> Default Constructor called" << std::endl;
	this->name = "Grunt";
	this->hp = FragTrap::hp;
	this->ep = ScavTrap::ep;
	this->at = FragTrap::at;
}

DiamondTrap::DiamondTrap(std::string name) {
	std::cout << "<DiamondTrap> Parameterized Constructor called" << std::endl;
	this->name = name;
	this->hp = 100;
	this->ep = 100;
	this->at = 30;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "<DiamondTrap> Deconstructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount) {
	this->hp -= amount;
	if (this->hp < 0)
		this->hp = 0;
	std::cout
		<< "DiamondTrap "
		<< this->name
		<< " lost "
		<< amount
		<< " health! | HP: "
		<< this->hp
	<< std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	this->ep -= 1;
	if (this->ep < 0)
		this->ep = 0;
	std::cout
		<< "DiamondTrap "
		<< this->name
		<< " used 1 EP to repair itself for "
		<< amount
		<< " health! | EP: "
		<< this->ep
	<< std::endl;
}

void 	DiamondTrap::whoAmI(void) {
	std::cout
		<< "My DiamondTrap name is: "
		<< this->name
		<< ", and my ClapTrap name is: "
		<< ClapTrap::name
		<< "."
	<< std::endl;
}
