/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:40:34 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/01 15:51:44 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
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
		// Create Bureaucrats
		Bureaucrat Gojo("Gojo", 1);
		Bureaucrat Geoffrey("Geoffrey", 150);
		// Create ShrubberyForm
		ShrubberyCreationForm FirstForm;
		std::cout
			<< "\n"
			<< "Form name: " << FirstForm.getName() << "\n"
			<< "Sign grade: " << FirstForm.getMinSignGrade() << "\n"
			<< "Execute grade: " << FirstForm.getMinExecuteGrade()
		<< "\n";
		// Have Bureaucrat execute ShrubberyForm
		Geoffrey.executeForm(FirstForm); // Not Signed
		// Have Bureaucrat Sign ShrubberyForm
		Gojo.signForm(FirstForm);
		// Attempt again
		Geoffrey.executeForm(FirstForm); // Grade too low
		Gojo.executeForm(FirstForm);	 // Success


		std::cout
			<< "\n"
			<< "---- Robotomy -----"
		<< "\n";

		RobotomyRequestForm SecondForm;
		std::cout
			<< "\n"
			<< "Form name: " << SecondForm.getName() << "\n"
			<< "Sign grade: " << SecondForm.getMinSignGrade() << "\n"
			<< "Execute grade: " << SecondForm.getMinExecuteGrade()
		<< "\n";
		// Have Bureaucrat execute RobotomyForm
		Geoffrey.executeForm(SecondForm);  // Not Signed
		// Have Bureaucrat Sign RobotomyForm
		Gojo.signForm(SecondForm);
		// Attempt again
		Geoffrey.executeForm(SecondForm); // Grade too low
		Gojo.executeForm(SecondForm);	  // Success


		std::cout
			<< "\n"
			<< "---- Presidential -----"
		<< "\n";

		PresidentialPardonForm ThirdForm;
		std::cout
			<< "\n"
			<< "Form name: " << ThirdForm.getName() << "\n"
			<< "Sign grade: " << ThirdForm.getMinSignGrade() << "\n"
			<< "Execute grade: " << ThirdForm.getMinExecuteGrade()
		<< "\n";
		// Have Bureaucrat execute PresidentialForm
		Geoffrey.executeForm(ThirdForm);  // Not Signed
		// Have Bureaucrat Sign PresidentialForm
		Gojo.signForm(ThirdForm);
		// Attempt again
		Geoffrey.executeForm(ThirdForm); // Grade too low
		Gojo.executeForm(ThirdForm);	 // Success

		std::cout << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
