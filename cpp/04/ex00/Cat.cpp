/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:11:05 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 15:28:12 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout
		<< "<Cat> Default Constructor called"
	<< std::endl;
}

Cat::~Cat() {
	std::cout
		<< "<Cat> Default Destructor called"
	<< std::endl;
}

void	Cat::makeSound() const {
	std::cout
		<< "Meow"
	<< std::endl;
}
