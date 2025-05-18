/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/18 13:38:36 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/18 14:01:40 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default Constructor called" << std::endl;
	this->name = "Grunt";
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Parameterized Constructor called" << std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap() {
	std::cout << "Deconstructor called" << std::endl;
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
	std::cout
		<< "ClapTrap "
		<< this->name
		<< " lost "
		<< amount
		<< " health!"
	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout
		<< "ClapTrap "
		<< this->name
		<< " repaired itself for "
		<< amount
		<< " health!"
	<< std::endl;
}
