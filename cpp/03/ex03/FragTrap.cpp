/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:19:29 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/07 11:04:35 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "<FragTrap> Default Constructor called" << std::endl;
	_name = "Grunt";
	_hp = 100;
	_ep = 100;
	_at = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "<FragTrap> Parameterized Constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 100;
	_at = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "<FragTrap> Copy Constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "<FragTrap> Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_at = other._at;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "<FragTrap> Deconstructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (_ep <= 0) {
		std::cout
			<< "FragTrap "
			<< _name
			<< " is out of energy!"
		<< std::endl;
		return;
	}

	_ep -= 1;
	std::cout
		<< "FragTrap "
		<< _name
		<< " attacks "
		<< target
		<< ", causing "
		<< _at
		<< " points of damage!"
	<< std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	_hp -= amount;
	if (_hp < 0) {
		amount += _hp;
		_hp = 0;
	}

	std::cout
		<< "FragTrap "
		<< _name
		<< " lost "
		<< amount
		<< " health! | HP: "
		<< _hp
	<< std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout
			<< "FragTrap "
			<< _name
			<< " is out of energy!"
		<< std::endl;
		return;
	}

	_hp += amount;	// no mention of max hp in subject, so let it go over 10
	_ep -= 1;
	std::cout
		<< "FragTrap "
		<< _name
		<< " used 1 EP to repair itself for "
		<< amount
		<< " health! | HP: "
		<< _hp
		<< " | EP: "
		<< _ep
	<< std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout
		<< "FragTrap "
		<< _name
		<< " is looking to high five."
	<< std::endl;
}
