/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:28:28 by nmattos-          #+#    #+#             */
/*   Updated: 2026/02/05 15:15:17 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : _name("Default"), _isSigned(false), _minGradeToSign(150), _minGradeToExecute(150) {
	std::cout
		<< "<Form> Default Constructor called"
	<< "\n";
}

Form::Form(std::string name, bool isSigned, int minGradeToSign, int minGradeToExecute) :
	_name(name),
	_isSigned(isSigned),
	_minGradeToSign(minGradeToSign),
	_minGradeToExecute(minGradeToExecute)
{
	std::cout
		<< "<Form> Parameterized Constructor called"
	<< "\n";
	if (minGradeToSign < 1) {
		throw Form::GradeTooHighException();
	}
	if (minGradeToSign > 150) {
		throw Form::GradeTooLowException();
	}
	if (minGradeToExecute < 1) {
		throw Form::GradeTooHighException();
	}
	if (minGradeToExecute > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_minGradeToSign(other._minGradeToSign),
	_minGradeToExecute(other._minGradeToExecute)
{
	std::cout
		<< "<Form> Copy Constructor called"
	<< "\n";
	if (_minGradeToSign < 1) {
		throw Form::GradeTooHighException();
	}
	if (_minGradeToSign > 150) {
		throw Form::GradeTooLowException();
	}
	if (_minGradeToExecute < 1) {
		throw Form::GradeTooHighException();
	}
	if (_minGradeToExecute > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::~Form() {
	std::cout
		<< "<Form> Destructor called"
	<< "\n";
}

const std::string	Form::getName() const {
	return (_name);
}

int	Form::getSigned() const {
	return (_isSigned);
}

int	Form::getMinSignGrade() const {
	return (_minGradeToSign);
}

int	Form::getMinExecuteGrade() const {
	return (_minGradeToExecute);
}

void	Form::beSigned(const Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() > this->_minGradeToSign) {
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream &out, const Form& form) {
	out << "Name: " << form.getName()
		<< "\nSigned: " << form.getSigned()
		<< "\nMin Grade to Sign: " << form.getMinSignGrade()
		<< "\nMin Grade to Execute: " << form.getMinExecuteGrade()
		<< ".";
	return (out);
}
