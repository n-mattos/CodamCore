/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:05:30 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 15:27:44 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout
		<< "<Animal> Default Constructor called"
	<< std::endl;
}

Animal::~Animal() {
	std::cout
		<< "<Animal> Default Destructor called"
	<< std::endl;
}

void	Animal::makeSound() const {
	std::cout
		<< "..."
	<< std::endl;
}

std::string	Animal::getType() const {
	return (this->type);
}
