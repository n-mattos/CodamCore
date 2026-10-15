/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:06:51 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/15 16:25:43 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>

#define USAGE "./PmergeMe 3 5 9 7 4\n./PmergeMe `jot -r 3000 1 100000 | tr '\\n' ' '`"

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Error: Too few arguments\n" << USAGE << std::endl;
		return (1);
	}

	try {
		std::vector<int> vector;
		Ford::sort(vector);

		std::deque<int> deque;
		Ford::sort(deque);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}