/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:01:01 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/05 15:04:08 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABC.hpp"
#include <iostream>

// Randomly instantiate A, B, or C.
// Return as a Base*
Base* generate(void) {
	srand(time(0));
	int randomNumber = rand() % 3;

	switch (randomNumber) {
		case 0:
			std::cout << "Created type A" << "\n\n";
			return (new A());
		case 1:
			std::cout << "Created type B" << "\n\n";
			return (new B());
		case 2:
			std::cout << "Created type C" << "\n\n";
			return (new C());
		default:
			break;
	}

	std::cout << "Something went wrong in generate()" << "\n";
	return (NULL);
}

// Print actual type 'p' points to
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

// Print actual type 'p' references
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
