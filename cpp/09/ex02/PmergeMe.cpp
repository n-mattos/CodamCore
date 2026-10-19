/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:06:58 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/19 12:00:13 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int Ford::validateAlgorithm(int n) {
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return (sum);
}

unsigned int Ford::Jacobsthal(unsigned int n) {
	return ((std::pow(2, n + 1) + std::pow(-1, n)) / 3 - 1);
}

unsigned int Ford::elementIndex(unsigned int elementSize, unsigned int n) {
	return (n * elementSize - elementSize);
}

unsigned int Ford::getA(unsigned int n) {
	return (n * 2);
}

unsigned int Ford::getB(unsigned int n) {
	return (n * 2 - 1);
}
