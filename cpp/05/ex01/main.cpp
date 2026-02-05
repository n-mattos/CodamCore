/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:49:26 by nmattos-          #+#    #+#             */
/*   Updated: 2026/02/05 15:16:41 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat Geoffrey("Geoffrey", 39);
		std::cout << Geoffrey << '\n';
		Form Unemployment("Unemployment", false, 50, 30);
		std::cout << Unemployment << '\n';
		Geoffrey.signForm(Unemployment);

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	return (0);
}
