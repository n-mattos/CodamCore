/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:54:50 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/10 11:41:20 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
	Array<int> a(2);
	a.logArray();

	std::cout << "\n";

	a[0] = 42;
	a[1] = 21;
	a.logArray();

	std::cout << "\n";

	try {
		a[5] = 100;
	} catch (const std::out_of_range &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n";

	Array<int> b = a;
	b.logArray();

	std::cout << "\n";

	Array<int> c(a);
	c.logArray();
}
