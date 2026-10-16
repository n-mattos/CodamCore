/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:06:51 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/16 12:02:37 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>

#define USAGE "./PmergeMe 3 5 9 7 4\n./PmergeMe `jot -r 3000 1 100000 | tr '\\n' ' '`"

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
		std::vector<int> vector;
		fillContainer(vector, argv);
		// Ford::sort(vector);
    	std::cout << vector << '\n';

		std::deque<int> deque;
		fillContainer(deque, argv);
		// Ford::sort(deque);
    	std::cout << deque << '\n';
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}