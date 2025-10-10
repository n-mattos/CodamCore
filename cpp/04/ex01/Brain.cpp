/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:48:43 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 10:26:10 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout
		<< "<Brain> Default Constructor called"
	<< "\n";
}

Brain::Brain(const Brain &src) {
	std::cout
		<< "<Brain> Copy Constructor called"
	<< "\n";
	*this = src;
}

Brain &Brain::operator=(const Brain &src) {
	std::cout
		<< "<Brain> Copy Assignment Operator called"
	<< "\n";
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout
		<< "<Brain> Default Destructor called"
	<< "\n";
}
