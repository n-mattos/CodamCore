/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:11:05 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 10:22:03 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout
		<< "<Cat> Default Constructor called"
	<< "\n";
}

Cat::~Cat() {
	std::cout
		<< "<Cat> Default Destructor called"
	<< "\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout
		<< "<Cat> Copy Constructor called"
	<< "\n";
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout
		<< "<Cat> Copy Assignment Operator called"
	<< "\n";
	return (*this);
}

void	Cat::makeSound() const {
	std::cout
		<< "Meow"
	<< "\n";
}

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout
		<< "<WrongCat> Default Constructor called"
	<< "\n";
}

WrongCat::~WrongCat() {
	std::cout
		<< "<WrongCat> Default Destructor called"
	<< "\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout
		<< "<WrongCat> Copy Constructor called"
	<< "\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout
		<< "<WrongCat> Copy Assignment Operator called"
	<< "\n";
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout
		<< "Maaaooow"
	<< "\n";
}
