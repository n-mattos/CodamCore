/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:01:01 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/07 15:18:49 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABC.hpp"
#include <iostream>

Base* generate(void) {
	srand(time(0));
	int randomNumber = rand() % 3;

	switch (randomNumber) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			break;
	}

	std::cout << "Something went wrong in generate()" << "\n";
	return (NULL);
}

void identify(Base* p) {
	std::cout << "Identifying by pointer:" << "\n";

	if (dynamic_cast<A*>(p))
		std::cout << "\tIdentified as A" << "\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "\tIdentified as B" << "\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "\tIdentified as C" << "\n";
	else
		std::cout << "\tCouldn't identify." << "\n";
}

void identify(Base& p) {
	std::cout << "Identifying by reference:" << "\n";

	// on bad cast, dynamic_cast throws a std::bad_cast exception
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "\tIdentified as A" << "\n";
		return;
	} catch (const std::bad_cast&) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "\tIdentified as B" << "\n";
		return;
	} catch (const std::bad_cast&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "\tIdentified as C" << "\n";
		return;
	} catch (const std::bad_cast&) {}
	std::cout << "\tCouldn't identify." << "\n";
}

int main() {
	Base* p = generate();

	identify(p);
	identify(*p);

	delete (p);
}
