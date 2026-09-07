/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:30:34 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/07 11:14:13 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		std::cout
			<< "Usage: ./a.out run [input]\n"
			<< "Testing: ./a.out test"
		<< "\n";
	} else if (argv[1] == std::string("test")) {
		ScalarConverter::convert("0");
		std::cout << "\n";
		ScalarConverter::convert("0.0");
		std::cout << "\n";
		ScalarConverter::convert("0.0f");
		std::cout << "\n";
		ScalarConverter::convert("x");
		std::cout << "\n";
		ScalarConverter::convert("=");
		std::cout << "\n";
		ScalarConverter::convert("nan");
		std::cout << "\n";
		ScalarConverter::convert("42.0f");
		std::cout << "\n";
		ScalarConverter::convert("42");
		std::cout << "\n";
		ScalarConverter::convert("Random String");
		std::cout << "\n";
		ScalarConverter::convert("-100000000000000.0f");
	} else if (argv[1] == std::string("run") && argc == 3) {
		ScalarConverter::convert(argv[2]);
	} else {
		std::cout
			<< "Usage: ./a.out run [input]\n"
			<< "Testing: ./a.out test"
		<< "\n";
	}

	return (0);
}
