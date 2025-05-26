/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:19:19 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 11:19:21 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "<ClapTrap> Default Constructor called" << std::endl;
	this->name = "Grunt";
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "<ClapTrap> Parameterized Constructor called" << std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap() {
	std::cout << "<ClapTrap> Deconstructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout
		<< "ClapTrap "
		<< this->name
		<< " attacks "
		<< target
		<< ", causing "
		<< this->at
		<< " points of damage!"
	<< std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount) {
	this->hp -= amount;
	if (this->hp < 0)
		this->hp = 0;
	std::cout
		<< "ClapTrap "
		<< this->name
		<< " lost "
		<< amount
		<< " health! | HP: "
		<< this->hp
	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	this->ep -= 1;
	if (this->ep < 0)
		this->ep = 0;
	std::cout
		<< "ClapTrap "
		<< this->name
		<< " used 1 EP to repair itself for "
		<< amount
		<< " health! | EP: "
		<< this->ep
	<< std::endl;
}
