/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:42:58 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/01 15:46:58 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("Default"), _isSigned(false), _minGradeToSign(150), _minGradeToExecute(150) {
	std::cout
		<< "<Form> Default Constructor called"
	<< "\n";
}

AForm::AForm(std::string name, bool isSigned, int minGradeToSign, int minGradeToExecute) :
	_name(name),
	_isSigned(isSigned),
	_minGradeToSign(minGradeToSign),
	_minGradeToExecute(minGradeToExecute)
{
	std::cout
		<< "<AForm> Parameterized Constructor called"
	<< "\n";
	if (minGradeToSign < 1) {
		throw AForm::GradeTooHighException();
	}
	if (minGradeToSign > 150) {
		throw AForm::GradeTooLowException();
	}
	if (minGradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	if (minGradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_minGradeToSign(other._minGradeToSign),
	_minGradeToExecute(other._minGradeToExecute)
{
	std::cout
		<< "<AForm> Copy Constructor called"
	<< "\n";
	if (_minGradeToSign < 1) {
		throw AForm::GradeTooHighException();
	}
	if (_minGradeToSign > 150) {
		throw AForm::GradeTooLowException();
	}
	if (_minGradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	if (_minGradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm() {
	std::cout
		<< "<AForm> Destructor called"
	<< "\n";
}

const std::string	AForm::getName() const {
	return (_name);
}

int	AForm::getSigned() const {
	return (_isSigned);
}

int	AForm::getMinSignGrade() const {
	return (_minGradeToSign);
}

int	AForm::getMinExecuteGrade() const {
	return (_minGradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() > this->_minGradeToSign) {
		throw AForm::GradeTooLowException();
	}
	this->_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	try {
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getMinExecuteGrade())
			throw AForm::GradeTooHighException();

		std::cout
			<< executor.getName() << " attempts to execute " << this->getName()
		<< "\n";

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Required grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Required grade is too low.");
}

const char* AForm::NotSignedException::what() const throw() {
	return ("Form is not signed.");
}

std::ostream& operator<<(std::ostream &out, const AForm& form) {
	out << "Name: " << form.getName()
		<< "\nSigned: " << form.getSigned()
		<< "\nMin Grade to Sign: " << form.getMinSignGrade()
		<< "\nMin Grade to Execute: " << form.getMinExecuteGrade()
		<< ".";
	return (out);
}
