/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:48:20 by nmattos-          #+#    #+#             */
/*   Updated: 2026/01/20 13:51:49 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout
		<< "<Bureaucrat> Copy Constructor called"
	<< "\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout
		<< "<Bureaucrat> Destructor called"
	<< "\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	std::cout
		<< "<Bureaucrat> Copy Assignment Operator called"
	<< "\n";
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
}

void Bureaucrat::decrementGrade() {
	// Higher grade == lower rank
	_grade++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}
