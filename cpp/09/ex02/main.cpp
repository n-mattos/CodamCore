/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 13:06:51 by nmattos-      #+#    #+#                 */
/*   Updated: 2026/10/18 19:18:19 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iomanip>

#define USAGE "./PmergeMe 3 5 9 7 4\n./PmergeMe $(shuf -i 1-100 -n 30 | tr '\\n' ' ')"

// Fill container with a positive integer sequence, built from the input string
template <typename Container>
void fillContainer(Container &c, char **input) {
	try {
		// Fill container
		for (char **number = input + 1; *number != nullptr; ++number) {
			int x = std::stoi(*number);
			if (x < 0)
				throw std::invalid_argument("Negative number is not allowed");
			c.push_back(x);
		}

	} catch (const std::exception &e) {
		throw std::invalid_argument(std::string("Parse input string: ") + e.what());
	}
}

// Allow easy vector printing
std::ostream& operator<<(std::ostream& out, const std::vector<int>& c) {
	for (auto i: c)
    	out << i << ' ';
	return (out);
}

// Allow easy deque printing
std::ostream& operator<<(std::ostream& out, const std::deque<int>& c) {
	for (auto i: c)
    	out << i << ' ';
	return (out);
}

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Error: Too few arguments\n" << USAGE << std::endl;
		return (1);
	}

	try {
		std::cout << std::left << std::setw(10) << "Before: ";
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << ' ';
		std::cout << '\n';

		std::vector<int> vector;
		fillContainer(vector, argv);

		auto durationVector = Ford::sort(vector);

		std::deque<int> deque;
		fillContainer(deque, argv);
		auto durationDeque = Ford::sort(deque);

		auto vectorTime = std::chrono::duration<double, std::micro>(durationVector).count() / 1000.0;
		auto dequeTime = std::chrono::duration<double, std::micro>(durationDeque).count() / 1000.0;

    	std::cout << std::left << std::setw(10) << "After: " << deque << '\n';
		std::cout
			<< "Time to process a range of "
			<< vector.size()
			<< std::setw(27) << " elements with std::vector"
			<< ": "
			<< std::fixed << std::setprecision(5) << vectorTime
		<< " us\n";
		std::cout
			<< "Time to process a range of "
			<< deque.size()
			<< std::setw(27) << " elements with std::deque"
			<< ": "
			<< std::fixed << std::setprecision(5) << dequeTime
		<< " us\n";
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}