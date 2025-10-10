/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:11:37 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 10:24:02 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout
		<< "<Dog> Default Constructor called"
	<< "\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
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
		this->_type = other._type;
	}
	return *this;
}

Dog::~Dog() {
	std::cout
		<< "<Dog> Default Destructor called"
	<< "\n";
}

void	Dog::makeSound() const {
	std::cout
		<< "Woof"
	<< "\n";
}
