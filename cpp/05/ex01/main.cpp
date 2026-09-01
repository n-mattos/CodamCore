/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:49:26 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/01 10:57:31 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "=== Bureaucrat and Form Test ===" << std::endl;
	try {
		Bureaucrat Geoffrey("Geoffrey", 39);
		std::cout << Geoffrey << '\n';
		Form Unemployment("Unemployment", false, 50, 30);
		std::cout << Unemployment << '\n';
		Geoffrey.signForm(Unemployment);

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Bureaucrat Grade Too Low Test ===" << std::endl;
	try {
		Bureaucrat Gojo("Gojo", 150);
		std::cout << Gojo << '\n';
		Form HireApplicant("HireApplicant", false, 115, 75);
		std::cout << HireApplicant << '\n';
		Gojo.signForm(HireApplicant);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
