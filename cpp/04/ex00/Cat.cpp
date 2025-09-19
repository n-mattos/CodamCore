/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:11:05 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 12:45:35 by nmattos-         ###   ########.fr       */
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

void	WrongCat::makeSound() const {
	std::cout
		<< "Maaaooow"
	<< "\n";
}
