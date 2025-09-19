/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:11:37 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 12:39:55 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout
		<< "<Dog> Default Constructor called"
	<< "\n";
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
