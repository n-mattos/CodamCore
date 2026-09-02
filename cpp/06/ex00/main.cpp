/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:30:34 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/02 16:12:44 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main() {
	std::cout
		<< "Start of program"
	<< "\n";

	ScalarConverter::convert("0");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("x");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("42.1532f");
	ScalarConverter::convert("42");

	float f = 42.1532f;
	std::cout << f << "\n";
}
