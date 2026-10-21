/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:47:28 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/21 11:44:23 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>
#include <sstream>
#include <stack>
#include <iostream>

// Pop 2, use operator, return result
float RPN::_performOperation(std::stack<float> *stack, std::string mathOperator) {
	if (stack->size() < 2)
		throw std::invalid_argument("Invalid input.");

	float y = stack->top();
	stack->pop();
	float x = stack->top();
	stack->pop();

	if (mathOperator.compare("+") == 0) {
		return (x + y);
	} else if (mathOperator.compare("-") == 0) {
		return (x - y);
	} else if (mathOperator.compare("*") == 0) {
		return (x * y);
	} else if (mathOperator.compare("/") == 0) {
		if (y == 0)
			throw std::invalid_argument("Division by zero");
		return (x / y);
	} else {
		throw std::invalid_argument("Not a number or valid mathOperator (+ - / *): " + mathOperator);
	}
}

float RPN::calculate(const std::string &input) {
	std::stack<float> stack;
	std::stringstream sstream(input);
	std::string element;

	try {
		while (sstream >> element) {
			// Handle negative numbers
			if (element[0] == '-' && element.length() > 1) {
				if (element.substr(1).find_first_not_of("0123456789") != std::string::npos)
					throw std::invalid_argument("Not a number or valid mathOperator (+ - / *): " + element);
				stack.push(std::stof(element));
				continue;
			}
			// If operator: Pop 2, calculate, Push
			if (element.find_first_not_of("0123456789") != std::string::npos) {
				stack.push(_performOperation(&stack, element));
			} else { // If number, Push
				stack.push(std::stof(element));
			}
		}
	} catch (const std::exception &e) {
		throw;
	}

	// If correct, stack should only have 1 number.
	if (stack.size() != 1)
		throw std::invalid_argument("Invalid input. (Too many numbers / Too few operators)");

	return (stack.top());
}
