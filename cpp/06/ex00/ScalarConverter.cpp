/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:24:12 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/02 16:21:36 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstring>
#include <iostream>
#include <iomanip>

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

	std::cout << "isChar: " << (isChar(input) ? "true" : "false") << "\n";
	std::cout << "isInt: " << (isInt(input) ? "true" : "false") << "\n";
	std::cout << "isFloat: " << (isFloat(input) ? "true" : "false") << "\n";
	std::cout << "isDouble: " << (isDouble(input) ? "true" : "false") << "\n";

	printChar(input);
	printInt(input);
}

void ScalarConverter::printChar(std::string input) {
	int intInput;
	// Check whether atoi was able to process the string
	if (!atoi(input.c_str(), intInput)) {
		std::cout
			<< "char: impossible"
		<< "\n";
		return;
	}

	// Print character
	if (intInput > 32 && intInput <= 126) {
		char c = static_cast<char>(intInput);

		std::cout
			<< "char: " << c
		<< "\n";
	// Not a printable character
	} else {
		std::cout
			<< "char: Non displayable"
		<< "\n";
	}
}

void ScalarConverter::printInt(std::string input) {
	int intInput;
	// Check whether atoi was able to process the string
	if (!atoi(input.c_str(), intInput)) {
		std::cout
			<< "int: impossible"
		<< "\n";
		return;
	}

	std::cout
		<< "int: " << intInput
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
	if (*nptr != '\0')
		return (false);
	value = sum * sign;
	return (true);
}

bool ScalarConverter::atof(const char *nptr, float &value) {
	double	sum = 0.0;
	double	sign = 1.0;
	bool	decimal = false;
	double	fraction = 0.1;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9')
		sum = (sum * 10) + (*(nptr++) - 48);
	// On decimal find
	if (*nptr == '.') {
		decimal = true;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9') {
		sum += (*(nptr++) - '0') * fraction;
		fraction *= 0.1;
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

bool ScalarConverter::atod(const char *nptr, float &value) {
	double	sum = 0.0;
	double	sign = 1.0;
	bool	decimal = false;
	double	fraction = 0.1;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9')
		sum = (sum * 10) + (*(nptr++) - 48);
	// On decimal find
	if (*nptr == '.') {
		decimal = true;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9') {
		sum += (*(nptr++) - '0') * fraction;
		fraction *= 0.1;
	}
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr != '\0' || !decimal)
		return (false);
	value = static_cast<float>(sum * sign);
	return (true);
}

bool ScalarConverter::isChar(std::string input) {
	if (input.length() == 1) {
		int value;
		return (!atoi(input.c_str(), value));
	}

	return (false);
}

bool ScalarConverter::isInt(std::string input) {
	int value;
	return (atoi(input.c_str(), value));
}

bool ScalarConverter::isFloat(std::string input) {
	float value;

	return (input.size() > 1
		&& input[input.size() - 1] == 'f'
		&& atof(input.c_str(), value));
}

bool ScalarConverter::isDouble(std::string input) {
	float value;

	return (input.size() > 1
		&& atod(input.c_str(), value));
}
