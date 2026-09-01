/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:06:46 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/01 15:48:00 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

#define MINSIGN 145
#define MINEXEC 137

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("DefaultShrubbery", false, MINSIGN, MINEXEC) {
	std::cout
		<< "<ShrubberyCreationForm> Default Constructor called"
	<< "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, false, MINSIGN, MINEXEC) {
	std::cout
		<< "<ShrubberyCreationForm> Parameterized Constructor called"
	<< "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	std::cout
		<< "<ShrubberyCreationForm> Copy Constructor called"
	<< "\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout
		<< "<ShrubberyCreationForm> Default Destructor called"
	<< "\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	try {
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getMinExecuteGrade())
			throw AForm::GradeTooHighException();

		std::cout
			<< executor.getName() << " attempts to execute " << this->getName()
		<< "\n";

		std::ofstream File(this->getName() + "_shrubbery");
		File << "      '.,"					<< '\n';
		File << "        'b      *"			<< '\n';
		File << "         '$    #."			<< '\n';
		File << "          $:   #:"			<< '\n';
		File << "          *#  @):"			<< '\n';
		File << "          :@,@):   ,.**:'"	<< '\n';
		File << " ,         :@@*: ..**'"	<< '\n';
		File << " '#o.    .:(@'.@*''"		<< '\n';
		File << "    'bq,..:,@@*'   ,*"		<< '\n';
		File << "    ,p$q8,:@)'  .p*'"		<< '\n';
		File << "   '    '@@Pp@@*'"			<< '\n';
		File << "         Y7'.'"			<< '\n';
		File << "        :@):."				<< '\n';
		File << "       .:@:'."				<< '\n';
		File << "     .::(@:."				<< '\n';
		File.close();

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
