/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:19:29 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 12:57:09 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "<FragTrap> Default Constructor called" << "\n";
	_name = "Grunt";
	_hp = 100;
	_ep = 100;
	_at = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "<FragTrap> Parameterized Constructor called" << "\n";
	_name = name;
	_hp = 100;
	_ep = 100;
	_at = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "<FragTrap> Copy Constructor called" << "\n";
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "<FragTrap> Copy Assignment Operator called" << "\n";
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_at = other._at;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "<FragTrap> Deconstructor called" << "\n";
}

void	FragTrap::attack(const std::string& target) {
	if (_ep <= 0) {
		std::cout
			<< "FragTrap "
			<< _name
			<< " is out of energy!"
		<< "\n";
		return;
	}
	if (_hp <= 0) {
		std::cout
			<< "FragTrap "
			<< _name
			<< " is dead!"
		<< "\n";
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
	<< "\n";
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
	<< "\n";
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout
			<< "FragTrap "
			<< _name
			<< " is out of energy!"
		<< "\n";
		return;
	}
	if (_hp <= 0) {
		std::cout
			<< "FragTrap "
			<< _name
			<< " is dead!"
		<< "\n";
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
	<< "\n";
}

void FragTrap::highFivesGuys(void) {
	if (_hp <= 0) {
		std::cout
			<< "FragTrap "
			<< _name
			<< " is dead!"
		<< "\n";
		return;
	}

	std::cout
		<< "FragTrap "
		<< _name
		<< " is looking to high five."
	<< "\n";
}
