/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:54:50 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/08 12:08:53 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
	std::cout << "New (empty, size 2)\n";
	Array<int> a(2);
	a.logArray();

	std::cout << "\nSize of array\n" << a.size() << "\n";

	std::cout << "\nAssign values\n";
	a[0] = 42;
	a[1] = 21;
	a.logArray();

	std::cout << "\nOut of bounds exception\n";
	try {
		a[5] = 100;
	} catch (const std::out_of_range &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nAssignment operator\n";
	Array<int> b = a;
	b.logArray();

	std::cout << "\nCopy constructor\n";
	Array<int> c(a);
	c.logArray();

	std::cout << "\nEdit copies\n";
	b[0] = 100;
	b.logArray();
	std::cout << "\n";
	c[1] = 200;
	c.logArray();

	std::cout << "\nOriginal (unchanged)\n";
	a.logArray();
}
