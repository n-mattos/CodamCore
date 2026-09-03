/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:24:12 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/03 13:49:38 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <functional>
#include <limits>

ScalarConverter::ScalarConverter() {
	std::cout
		<< "<ScalarConverter> Default Constructor called"
	<< "\n";
}

ScalarConverter::~ScalarConverter() {
	std::cout
		<< "<ScalarConverter> Destructor called"
	<< "\n";
}

void ScalarConverter::convert(std::string input) {
	std::cout
		<< "\nConverting <" << input << ">"
	<< "\n";

	// Check for pseudo-literals
	if (input.compare("-inff") == 0
		|| input.compare("+inff") == 0
		|| input.compare("nanf") == 0
		|| input.compare("-inf") == 0
		|| input.compare("+inf") == 0
		|| input.compare("nan") == 0) {
		printPseudo(input);
		return;
	}

	enum Type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
	};

	// Array of function pointers
	// Order matters, as the index is used to determine the type of literal.
	std::function<bool(std::string)> typeCheckers[] = {
		[](std::string target) { return isChar(target); },
		[](std::string target) { return isInt(target); },
		[](std::string target) { return isFloat(target); },
		[](std::string target) { return isDouble(target); }
	};

	// Loop the type checkers and set literalType to the first matching type
	// Once a match is found, the loop breaks and no further checks are made.
	for (int i = 0; i < 4; i++) {
		if (typeCheckers[i](input)) {
			switch (i) {
				case CHAR:
					printChar(input);
					break;
				case INT:
					printInt(input);
					break;
				case FLOAT:
					printFloat(input);
					break;
				case DOUBLE:
					printDouble(input);
					break;
			}
			break;
		}
		if (i == 3) {
			std::cout
				<< "Conversion not possible; Input is not part of {Char, Int, Float, Double}"
			<< "\n";
		}
	}
}

void ScalarConverter::printPseudo(std::string input) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";

	if (input == "-inff" || input == "+inff" || input == "nanf")
		std::cout << "float: " << input << "\n";
	else
		std::cout << "float: " << input << "f\n";

	if (input == "-inff" || input == "+inff" || input == "nanf")
		std::cout << "double: " << input.substr(0, input.size() - 1) << "\n";
	else
		std::cout << "double: " << input << "\n";
}

void ScalarConverter::printChar(std::string input) {
	// Char
	char charInput = input.c_str()[0];
	std::cout
		<< "char: " << charInput
	<< "\n";

	// Int
	int i = static_cast<int>(charInput);
	std::cout
		<< "int: " << i
	<< "\n";

	// Float
	float f = static_cast<float>(charInput);
	std::cout
		<< "float: " << std::fixed << std::setprecision(1)
		<< f << "f"
	<< "\n";

	// Double
	double d = static_cast<double>(charInput);
	std::cout
		<< "double: " << std::fixed << std::setprecision(1)
		<< d
	<< "\n";
}

void ScalarConverter::printInt(std::string input) {
	int intInput;
	// Check whether calcInt was able to process the string
	calcInt(input.c_str(), intInput);

	// Char
	char c = static_cast<char>(intInput);
	if (c > 32 && c <= 126) {
		std::cout
			<< "char: " << c
		<< "\n";
	} else {
		std::cout
			<< "char: Non displayable"
		<< "\n";
	}

	// Int
	std::cout
		<< "int: " << intInput
	<< "\n";

	// Float
	float f = static_cast<float>(intInput);
	std::cout
		<< "float: " << std::fixed << std::setprecision(1)
		<< f << "f"
	<< "\n";

	// Double
	double d = static_cast<double>(intInput);
	std::cout
		<< "double: " << std::fixed << std::setprecision(1)
		<< d
	<< "\n";
}

void ScalarConverter::printFloat(std::string input) {
	float floatInput;
	calcFloat(input.c_str(), floatInput);

	// Char
	char c = static_cast<char>(floatInput);
	if (c > 32 && c <= 126) {
		std::cout
			<< "char: " << c
		<< "\n";
	} else {
		std::cout
			<< "char: Non displayable"
		<< "\n";
	}

	// Int
	if (floatInput > static_cast<double>(std::numeric_limits<int>::max())
		|| floatInput < static_cast<double>(std::numeric_limits<int>::lowest())) {
		std::cout
			<< "int: impossible"
		<< "\n";
	} else {
		int i = static_cast<int>(floatInput);
		std::cout
			<< "int: " << i
		<< "\n";
	}

	// Float
	std::cout
		<< "float: " << std::fixed << std::setprecision(1)
		<< floatInput << "f"
	<< "\n";

	// Double
	double d = static_cast<double>(floatInput);
	std::cout
		<< "double: " << std::fixed << std::setprecision(1)
		<< d
	<< "\n";
}

void ScalarConverter::printDouble(std::string input) {
	double doubleInput;
	calcDouble(input.c_str(), doubleInput);

	// Char
	char c = static_cast<char>(doubleInput);
	if (c > 32 && c <= 126) {
		std::cout
			<< "char: " << c
		<< "\n";
	} else {
		std::cout
			<< "char: Non displayable"
		<< "\n";
	}

	// Int
	if (doubleInput > std::numeric_limits<int>::max()
		|| doubleInput < std::numeric_limits<int>::lowest()) {
		std::cout
			<< "int: impossible"
		<< "\n";
	} else {
		int i = static_cast<int>(doubleInput);
		std::cout
			<< "int: " << i
		<< "\n";
	}

	// Float
	float f = static_cast<float>(doubleInput);
	std::cout
		<< "float: " << std::fixed << std::setprecision(1)
		<< f << "f"
	<< "\n";

	// Double
	std::cout
		<< "double: " << std::fixed << std::setprecision(1)
		<< doubleInput
	<< "\n";
}


bool ScalarConverter::atoi(const char *nptr, int &value) {
	int	sum = 0;
	int	sign = 1;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9')
		sum = (sum * 10) + (*(nptr++) - 48);
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	value = sum * sign;
	return (true);
}

bool ScalarConverter::calcInt(const char *nptr, int &value) {
	long	sum = 0;
	long	sign = 1;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9') {
		sum = (sum * 10) + (*(nptr++) - 48);
		// Overflow/Underflow check
		if (sum * sign > (std::numeric_limits<int>::max())
			|| sum * sign < (std::numeric_limits<int>::lowest()))
			return (false);
		if (sign == -1 && (std::numeric_limits<int>::max() - (*(nptr) - 48) / 10) < sum)
			return (false);
	}
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr != '\0')
		return (false);
	value = sum * sign;
	return (true);
}

bool ScalarConverter::calcFloat(const char *nptr, float &value) {
	long double	sum = 0.0;
	long double	sign = 1.0;
	bool		decimal = false;
	long double	fraction = 0.1;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9') {
		sum = (sum * 10) + (*(nptr++) - 48);
		// Overflow/Underflow check
		if (sum * sign > (std::numeric_limits<float>::max())
			|| sum * sign < (std::numeric_limits<float>::lowest()))
			return (false);
	}
	// On decimal find
	if (*nptr == '.') {
		decimal = true;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9') {
		sum += (*(nptr++) - '0') * fraction;
		fraction *= 0.1;
		// Overflow/Underflow check
		if (sum * sign > (std::numeric_limits<float>::max())
			|| sum * sign < (std::numeric_limits<float>::lowest()))
			return (false);
	}
	if (*nptr == 'f')
		nptr++;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr != '\0' || !decimal)
		return (false);
	value = static_cast<float>(sum * sign);
	return (true);
}

bool ScalarConverter::calcDouble(const char *nptr, double &value) {
	long double	sum = 0.0;
	long double	sign = 1.0;
	bool		decimal = false;
	long double	fraction = 0.1;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9') {
		sum = (sum * 10) + (*(nptr++) - 48);
		// Overflow/Underflow check
		if (sum * sign > (std::numeric_limits<double>::max())
			|| sum * sign < (std::numeric_limits<double>::lowest()))
			return (false);
	}
	// On decimal find
	if (*nptr == '.') {
		decimal = true;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9') {
		sum += (*(nptr++) - '0') * fraction;
		fraction *= 0.1;
		// Overflow/Underflow check
		if (sum * sign > (std::numeric_limits<double>::max())
			|| sum * sign < (std::numeric_limits<double>::lowest()))
			return (false);
	}
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr != '\0' || !decimal)
		return (false);
	value = static_cast<double>(sum * sign);
	return (true);
}

bool ScalarConverter::isChar(std::string input) {
	if (input.length() == 1) {
		int value;
		return (!calcInt(input.c_str(), value));
	}

	return (false);
}

bool ScalarConverter::isInt(std::string input) {
	int value;
	return (calcInt(input.c_str(), value));
}

bool ScalarConverter::isFloat(std::string input) {
	float value;

	return (input.size() > 1
		&& input[input.size() - 1] == 'f'
		&& calcFloat(input.c_str(), value));
}

bool ScalarConverter::isDouble(std::string input) {
	double value;

	return (input.size() > 1
		&& calcDouble(input.c_str(), value));
}
