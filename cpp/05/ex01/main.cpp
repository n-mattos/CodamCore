/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:49:26 by nmattos-          #+#    #+#             */
/*   Updated: 2026/02/05 12:12:35 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat Geoffrey("Geoffrey", 39);

		std::cout << Geoffrey << '\n';
		Geoffrey.incrementGrade();
		std::cout << Geoffrey << '\n';
		Geoffrey.decrementGrade();
		std::cout << Geoffrey << '\n';

		Bureaucrat Invalid("Invalid", 0);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "-----------------------------\n";

	try {
		Bureaucrat Gojo("Gojo", 1);
		std::cout << Gojo << '\n';
		Gojo.incrementGrade();
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	return (0);
}
