/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:11:05 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 10:29:12 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain) {
	std::cout
		<< "<Cat> Default Constructor called"
	<< "\n";
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*(other._brain))) {
	std::cout
		<< "<Cat> Copy Constructor called"
	<< "\n";
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout
		<< "<Cat> Copy Assignment Operator called"
	<< "\n";
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*(other._brain));
	}
	return *this;
}

Cat::~Cat() {
	std::cout
		<< "<Cat> Default Destructor called"
	<< "\n";

	delete _brain;
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

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout
		<< "<WrongCat> Copy Constructor called"
	<< "\n";
	*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout
		<< "<WrongCat> Copy Assignment Operator called"
	<< "\n";
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout
		<< "<WrongCat> Default Destructor called"
	<< "\n";
}

void	WrongCat::makeSound() const {
	std::cout
		<< "Maaaooow"
	<< "\n";
}
