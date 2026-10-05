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
		std::cout << "\nOwn test(s):" << "\n";
		std::vector<int> numbers = {1, 2, 3, 4, 5};
		sp.addMultiple(numbers.begin(), numbers.end());

		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";
		std::cout << sp << "\n";
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
		return (1);
	}

	return (0);
}