/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:11:37 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 15:28:05 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout
		<< "<Dog> Default Constructor called"
	<< std::endl;
}

Dog::~Dog() {
	std::cout
		<< "<Dog> Default Destructor called"
	<< std::endl;
}

void	Dog::makeSound() const {
	std::cout
		<< "Woof"
	<< std::endl;
}
