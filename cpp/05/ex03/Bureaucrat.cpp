/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:48:20 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/01 15:49:52 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout
		<< "<Bureaucrat> Default Constructor called"
	<< "\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout
		<< "<Bureaucrat> Parameterized Constructor called"
	<< "\n";
	if (grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade < 1) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout
		<< "<Bureaucrat> Copy Constructor called"
	<< "\n";
	if (other._grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (other._grade < 1) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout
		<< "<Bureaucrat> Destructor called"
	<< "\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout
		<< "<Bureaucrat> Copy Assignment Operator called"
	<< "\n";
	if (this != &other) {
		_grade = other._grade;
	}
	if (_grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (_grade < 1) {
		throw Bureaucrat::GradeTooLowException();
	}
	return (*this);
}

const std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementGrade() {
	// Lower grade == higher rank
	_grade--;
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade() {
	// Higher grade == lower rank
	_grade++;
	if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << ".\n";
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because: " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because: " << e.what() << '\n';
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}
