/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:36:39 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/08 12:30:58 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
	try {
		Span sp = Span(15);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";
		std::cout << sp << "\n";

		// Own test(s)
		std::cout << "\n\nOwn test(s):" << "\n";
		std::cout << "\nCopy constructor\n";
		Span sp2(sp);
		std::cout << sp2 << "\n";

		std::cout << "\nAssignment operator\n";
		Span sp3 = sp;
		std::cout << sp3 << "\n";

		std::cout << "\nChange sp2/sp3 and check if sp is unchanged\n";
		sp2.addNumber(20);
		sp3.addNumber(25);
		std::cout << "sp1: " << sp << "\n";
		std::cout << "sp2: " << sp2 << "\n";
		std::cout << "sp3: " << sp3 << "\n";

		std::cout << "\nAdd 5 numbers using iterators:\n";
		std::vector<int> numbers = {1, 2, 3, 4, 5};
		sp.addMultiple(numbers.begin(), numbers.end());
		std::cout << sp << "\n";

		std::cout << "\nShortest and longest span\n";
		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";

		std::cout << "\n20000-number test:\n";
		Span largeSpan(20000);
		std::vector<int> bignumbers;
		for (int i = 0; i < 20000; i++)
			bignumbers.push_back(i);
		largeSpan.addMultiple(bignumbers.begin(), bignumbers.end());
		std::cout << "Size: " << largeSpan.getSize() << "\n";
		std::cout << "Shortest span: " << largeSpan.shortestSpan() << "\n";
		std::cout << "Longest span: " << largeSpan.longestSpan() << "\n";

		try {
			std::cout << "\nAttempt to overfill:\n";
			largeSpan.addNumber(20000);
			std::cout << "Error: number was added to a full Span\n";
		} catch (const Span::out_of_range &e) {
			std::cout << "Rejected extra number: "
					<< e.what() << "\n";
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
		return (1);
	}

	return (0);
}