/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:05:04 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/01 15:48:16 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define MINSIGN 72
#define MINEXEC 45

RobotomyRequestForm::RobotomyRequestForm() : AForm("DefaultRobotomy", false, MINSIGN, MINEXEC) {
	std::cout
		<< "<RobotomyRequestForm> Default Constructor called"
	<< "\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, false, MINSIGN, MINEXEC) {
	std::cout
		<< "<RobotomyRequestForm> Parameterized Constructor called"
	<< "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	std::cout
		<< "<RobotomyRequestForm> Copy Constructor called"
	<< "\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout
		<< "<RobotomyRequestForm> Default Destructor called"
	<< "\n";
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	try {
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getMinExecuteGrade())
			throw AForm::GradeTooHighException();

		std::cout
			<< executor.getName() << " attempts to execute " << this->getName()
		<< "\n";

		std::string result = (rand() % 2 == 0) ?
			(this->getName() + " has been robotomized.") :
			("The robotomy has failed.");

		std::cout
			<< "*Drill Noises* "
			<< result
		<< "\n";

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
