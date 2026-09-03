/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:30:34 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/03 12:16:36 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

int main() {
	std::cout
		<< "Start of program"
	<< "\n";

	ScalarConverter::convert("0");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("x");
	ScalarConverter::convert("=");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("42.0f");
	ScalarConverter::convert("42");
	ScalarConverter::convert("Random String");
	ScalarConverter::convert("-100000000000000.0f");
}
