/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:05:04 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/01 15:48:29 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define MINSIGN 25
#define MINEXEC 5

PresidentialPardonForm::PresidentialPardonForm() : AForm("DefaultPresidential", false, MINSIGN, MINEXEC) {
	std::cout
		<< "<PresidentialPardonForm> Default Constructor called"
	<< "\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, false, MINSIGN, MINEXEC) {
	std::cout
		<< "<PresidentialPardonForm> Parameterized Constructor called"
	<< "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	std::cout
		<< "<PresidentialPardonForm> Copy Constructor called"
	<< "\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout
		<< "<PresidentialPardonForm> Default Destructor called"
	<< "\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	try {
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getMinExecuteGrade())
			throw AForm::GradeTooHighException();

		std::cout
			<< executor.getName() << " attempts to execute " << this->getName()
		<< "\n";

		std::cout
			<< executor.getName()
			<< " has been excused by Zaphod Beeblebrox"
		<< "\n";

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
