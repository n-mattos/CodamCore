/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:05:30 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 10:21:12 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout
		<< "<Animal> Default Constructor called"
	<< "\n";
}

Animal::Animal(std::string type) : _type(type) {
	std::cout
		<< "<Animal> Parameterized Constructor called"
	<< "\n";
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout
		<< "<Animal> Copy Constructor called"
	<< "\n";
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout
		<< "<Animal> Copy Assignment Operator called"
	<< "\n";
	return (*this);
}

Animal::~Animal() {
	std::cout
		<< "<Animal> Default Destructor called"
	<< "\n";
}

void	Animal::makeSound() const {
	std::cout
		<< "..."
	<< "\n";
}

std::string	Animal::getType() const {
	return (_type);
}

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout
		<< "<WrongAnimal> Default Constructor called"
	<< "\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout
		<< "<WrongAnimal> Parameterized Constructor called"
	<< "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout
		<< "<WrongAnimal> Copy Constructor called"
	<< "\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout
		<< "<WrongAnimal> Copy Assignment Operator called"
	<< "\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout
		<< "<WrongAnimal> Default Destructor called"
	<< "\n";
}

void	WrongAnimal::makeSound() const {
	std::cout
		<< "..."
	<< "\n";
}

std::string	WrongAnimal::getType() const {
	return (_type);
}
