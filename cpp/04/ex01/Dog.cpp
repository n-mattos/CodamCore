/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:11:37 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 10:29:19 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain) {
	std::cout
		<< "<Dog> Default Constructor called"
	<< "\n";
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*(other._brain))) {
	std::cout
		<< "<Dog> Copy Constructor called"
	<< "\n";
	*this = other;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout
		<< "<Dog> Copy Assignment Operator called"
	<< "\n";
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*(other._brain));
	}
	return *this;
}

Dog::~Dog() {
	std::cout
		<< "<Dog> Default Destructor called"
	<< "\n";

	delete _brain;
}

void	Dog::makeSound() const {
	std::cout
		<< "Woof"
	<< "\n";
}
