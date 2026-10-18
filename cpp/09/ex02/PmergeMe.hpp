/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 13:06:56 by nmattos-      #+#    #+#                 */
/*   Updated: 2026/10/18 19:14:35 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PMERGEME
#define H_PMERGEME

#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <chrono>

enum Element {
	A = 1,
	B = 2
};

namespace Ford {
	// Validate the algorithm by calculating maximum number of comparisons needed to sort n elements
	unsigned int 	validateAlgorithm(int n);

	// Calculate the nth Jacobsthal number
	// n1 = 1, n2 = 1, n3 = 3, n4 = 5, n5 = 11, n6 = 21, ...
	unsigned int	Jacobsthal(unsigned int n);

	// Get the a index of a pair
	unsigned int	aIndex(unsigned int pairSize, unsigned int n);

	// Get the index of the first number in element a
	unsigned int	aStartIndex(unsigned int elementSize, unsigned int n);

	// Get the b index of a pair
	unsigned int	bIndex(unsigned int pairSize, unsigned int n);

	// Get the index of the first number in element b
	unsigned int	bStartIndex(unsigned int elementSize, unsigned int n);

	// Get the index of the first number in an element
	unsigned int	elementIndex(unsigned int elementSize, unsigned int n);

	// Push an element from src to dst
	template <typename Container>
	void	pushElement(Container &src, Container &dst, unsigned int elementSize, unsigned int n) {
		for (unsigned int i = 0; i < elementSize; i++) {
			dst.push_back(src.at(elementIndex(elementSize, n) + i));
		}
	}

	// Insert an element from src to dst before the element at index n
	template <typename Container>
	void	insertBefore(Container &src, Container &dst, unsigned int elementSize, unsigned int srcN, unsigned int dstN) {
		for (unsigned int i = 0; i < elementSize; i++) {
			dst.insert(dst.begin() + elementIndex(elementSize, dstN) + i, src.at(elementIndex(elementSize, srcN) + i));
		}
	}

	// pop an element from the container
	template <typename Container>
	void	popElement(Container &c, unsigned int elementSize, unsigned int n) {
		typename Container::iterator first = c.begin() + elementIndex(elementSize, n);
		typename Container::iterator last = first + elementSize;
		c.erase(first, last);
	}

	// Use binary search to find the index of the first element in container c that is
	// greater than or equal to the element at index n of container temp
	template <typename Container>
	int		binarySearch(Container &c, Container &temp, unsigned int elementSize, unsigned int n, unsigned int upperBound, unsigned int &comparisons) {
		int low = 1;
		int high = upperBound;

		while (low <= high) {
			++comparisons;
			int mid = (low + high) / 2;
			if (c.at(elementIndex(elementSize, mid) + elementSize - 1)
				< temp.at(elementIndex(elementSize, n) + elementSize - 1)) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return (low);
	}

	// Get the a value of a pair, given the pair size and pair index
	template <typename Container>
	int		aValue(Container &c, unsigned int pairSize, unsigned int n) {
		return (c.at(aIndex(pairSize, n)));
	}

	// Get the b value of a pair, given the pair size and pair index
	template <typename Container>
	int		bValue(Container &c, unsigned int pairSize, unsigned int n) {
		return (c.at(bIndex(pairSize, n)));
	}

	// Swap all elements of a pair, given the pair size and pair index
	template <typename Container>
	void	swapPair(Container &c, unsigned int pairSize, unsigned int n) {
		for (unsigned int i = 0; i < pairSize / 2; i++) {
			std::swap(c[bIndex(pairSize, n) - i], c[aIndex(pairSize, n) - i]);
		}
	}

	// Recursively sort the container, given the current depth
	template <typename Container>
	void	recursiveSort(Container &c, unsigned int depth, unsigned int &comparisons) {
		unsigned int pairSize = std::pow(2, depth);
		unsigned int totalPairs = c.size() / pairSize;

		if (totalPairs == 0) {
			return;
		}

		// n = pair index: b1, b2, b3, ..., bn
		for (unsigned int n = 1; n <= totalPairs; n++) {
			if (n * pairSize > c.size()) {
				std::cout << "Pair " << n << " is incomplete, skipping comparison\n";
				break;
			}
			// compare a and b values of each pair and sort them
			++comparisons;
			if (Ford::bValue(c, pairSize, n) > Ford::aValue(c, pairSize, n)) {
				Ford::swapPair(c, pairSize, n);
			}
		}

		Ford::recursiveSort(c, depth + 1, comparisons);

		Container temp;
		unsigned int elementSize = pairSize / 2;
		unsigned int totalElements = c.size() / elementSize;
		// Move every b but b1 into a temporary container
		for (unsigned int n = 2; n <= totalElements - totalElements / 2; n++) {
			Ford::pushElement(c, temp, elementSize, n * Element::B - 1);
		}
		// Remove every b but b1 from the original container
		for (int n = totalElements - totalElements / 2; n >= 2; --n) {
			Ford::popElement(c, elementSize, n * Element::B - 1);
		}

		// Insert temporary container into original container
		// Using Jacobsthal sequence to determine the order of insertion
		totalElements = temp.size() / elementSize;
		unsigned int previous = 0;
		unsigned int ithJacobsthal = 2;
		unsigned int current = Ford::Jacobsthal(ithJacobsthal);
		unsigned int insertedNumbers = 0;

		while (previous < totalElements) {
			unsigned int upper = std::min(current, totalElements);
			unsigned int searchLimit = upper + insertedNumbers + 1;
			for (unsigned int n = upper; n > previous; --n) {
				unsigned int dstN = Ford::binarySearch(c, temp, elementSize, n, searchLimit, comparisons);
				Ford::insertBefore(temp, c, elementSize, n, dstN);
				++insertedNumbers;
			}

			previous = upper;
			++ithJacobsthal;
			current = Ford::Jacobsthal(ithJacobsthal);
		}
	}

	template <typename Container>
	std::chrono::nanoseconds	sort(Container &c) {
		unsigned int comparisons = 0;

		auto start = std::chrono::high_resolution_clock::now();
		Ford::recursiveSort(c, 1, comparisons);
		auto end = std::chrono::high_resolution_clock::now();

		assert(std::is_sorted(c.begin(), c.end()));
		assert(comparisons <= Ford::validateAlgorithm(c.size()));

		return (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start));
	}
}

#endif
