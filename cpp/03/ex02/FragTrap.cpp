/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:19:29 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 11:28:59 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "<FragTrap> Default Constructor called" << std::endl;
	this->name = "Grunt";
	this->hp = 100;
	this->ep = 100;
	this->at = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "<FragTrap> Parameterized Constructor called" << std::endl;
	this->name = name;
	this->hp = 100;
	this->ep = 100;
	this->at = 30;
}

FragTrap::~FragTrap() {
	std::cout << "<FragTrap> Deconstructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	std::cout
		<< "FragTrap "
		<< this->name
		<< " attacks "
		<< target
		<< ", causing "
		<< this->at
		<< " points of damage!"
	<< std::endl;
}
void	FragTrap::takeDamage(unsigned int amount) {
	this->hp -= amount;
	if (this->hp < 0)
		this->hp = 0;
	std::cout
		<< "FragTrap "
		<< this->name
		<< " lost "
		<< amount
		<< " health! | HP: "
		<< this->hp
	<< std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	this->ep -= 1;
	if (this->ep < 0)
		this->ep = 0;
	std::cout
		<< "FragTrap "
		<< this->name
		<< " used 1 EP to repair itself for "
		<< amount
		<< " health! | EP: "
		<< this->ep
	<< std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout
		<< "FragTrap "
		<< this->name
		<< " is looking to high five."
	<< std::endl;
}
