/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:40:34 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/02 11:55:54 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define RED "\033[31m"

int main() {
	// Seed rand()
	srand(time(0));

	try {
		std::cout
			<< "\n"
			<< "---- Shrubbery -----"
		<< "\n";
		// Create Bureaucrat
		Bureaucrat Gojo("Gojo", 1);
		// Create Intern
		Intern RandomGuy;
		// Create ShrubberyForm
		AForm* FirstForm = RandomGuy.makeForm("shrubbery creation", "Garden");
		std::cout
			<< "\n"
			<< "Form target: " << FirstForm->getName() << "\n"
			<< "Sign grade: " << FirstForm->getMinSignGrade() << "\n"
			<< "Execute grade: " << FirstForm->getMinExecuteGrade()
		<< "\n";
		// Have Bureaucrat sign and execute ShrubberyForm
		Gojo.signForm(*FirstForm);
		Gojo.executeForm(*FirstForm);	 // Success

		std::cout << "\n";
		if (FirstForm) { delete FirstForm; }


		std::cout
			<< "---- Robotomy -----"
		<< "\n";

		AForm* SecondForm = RandomGuy.makeForm("robotomy request", "Factory");
		std::cout
			<< "\n"
			<< "Form name: " << SecondForm->getName() << "\n"
			<< "Sign grade: " << SecondForm->getMinSignGrade() << "\n"
			<< "Execute grade: " << SecondForm->getMinExecuteGrade()
		<< "\n";
		// Have Bureaucrat sign and execute RobotomyForm
		Gojo.signForm(*SecondForm);
		Gojo.executeForm(*SecondForm);	  // Success

		std::cout << "\n";
		if (SecondForm) { delete SecondForm; }

		std::cout
			<< "---- Presidential -----"
		<< "\n";

		AForm* ThirdForm = RandomGuy.makeForm("presidential pardon", "President");
		std::cout
			<< "\n"
			<< "Form name: " << ThirdForm->getName() << "\n"
			<< "Sign grade: " << ThirdForm->getMinSignGrade() << "\n"
			<< "Execute grade: " << ThirdForm->getMinExecuteGrade()
		<< "\n";
		// Have Bureaucrat sign and execute PresidentialForm
		Gojo.signForm(*ThirdForm);
		Gojo.executeForm(*ThirdForm);	 // Success

		std::cout << "\n";
		if (ThirdForm) { delete ThirdForm; }

		AForm* InvalidForm = RandomGuy.makeForm("fake request", "Invalid");
		if (InvalidForm) { delete InvalidForm; }

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
