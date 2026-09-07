/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:36:51 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/07 15:55:11 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

void square(int &x) {
	x *= x;
}

void toUpperCase(char &c) {
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void constFunction(const int &x) {
	std::cout << "Const function called with value: " << x << std::endl;
}

int main() {
	// INT ARRAY
	void (*func)(int &) = square;

	int arrlength = 5;
	int *arr = new int[arrlength]{1, 2, 3, 4, 5};

	std::cout << "Before iter:\t";
	for (int i = 0; i < arrlength; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	::iter(arr, 5, func);

	std::cout << "After iter:\t";
	for (int i = 0; i < arrlength; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	// CONST INT FUNCTION
	::iter<const int>(arr, 5, constFunction);

	delete[] arr;

	// CHAR ARRAY
	void (*func2)(char &) = toUpperCase;

	int arrlength2 = 5;
	char *arr2 = new char[arrlength2]{'a', 'b', 'c', 'd', 'e'};

	std::cout << "Before iter:\t";
	for (int i = 0; i < arrlength2; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	::iter(arr2, 5, func2);

	std::cout << "After iter:\t";
	for (int i = 0; i < arrlength2; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
}