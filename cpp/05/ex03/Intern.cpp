/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:55:39 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/02 11:51:58 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <functional>

Intern::Intern() {
	std::cout
		<< "<Intern> Default Constructor called"
	<< "\n";
}

Intern::~Intern() {
	std::cout
		<< "<Intern> Destructor called"
	<< "\n";
}

AForm*	Intern::makeForm(std::string name, std::string target) {
	// Array of form names
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Array of function (constructor) pointers
	std::function<AForm*(std::string)> formConstructors[] = {
		[](std::string target) { return new ShrubberyCreationForm(target); },
		[](std::string target) { return new RobotomyRequestForm(target); },
		[](std::string target) { return new PresidentialPardonForm(target); }
	};

	// Loop the form names to check for a match with 'name'
	// If found, the index is used to call the corresponding constructor.
	// This means the order of the form names and constructors must be the same.
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout
				<< "<Intern> creates " << name << " form."
			<< "\n";

			return (formConstructors[i](target));
		}
	}

	std::cout
		<< "<Intern> Error: Form '" << name << "' does not exist."
	<< "\n";

	return (nullptr);
}
