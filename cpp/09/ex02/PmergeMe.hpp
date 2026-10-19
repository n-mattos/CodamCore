/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:06:56 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/19 12:39:54 by nmattos-         ###   ########.fr       */
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

namespace Ford {
	// Validate the algorithm by calculating maximum number of comparisons needed to sort n elements
	unsigned int 	validateAlgorithm(int n);

	// Calculate the nth Jacobsthal number
	// n1 = 1, n2 = 1, n3 = 3, n4 = 5, n5 = 11, n6 = 21, ...
	unsigned int	Jacobsthal(unsigned int n);

	// Get the index of the first number in an element
	unsigned int	elementIndex(unsigned int elementSize, unsigned int n);

	// Get the element number of the a value in pair n
	unsigned int	getA(unsigned int n);

	// Get the element number of the b value in pair n
	unsigned int	getB(unsigned int n);

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

	// Get the a value of a pair
	template <typename Container>
	int		aValue(Container &c, unsigned int elementSize, unsigned int n) {
		return (c.at(elementIndex(elementSize, getA(n)) + elementSize - 1));
	}

	// Get the b value of a pair
	template <typename Container>
	int		bValue(Container &c, unsigned int elementSize, unsigned int n) {
		return (c.at(elementIndex(elementSize, getB(n)) + elementSize - 1));
	}

	// Swap all elements of a pair
	template <typename Container>
	void	swapPair(Container &c, unsigned int elementSize, unsigned int n) {
		for (unsigned int i = 0; i < elementSize; i++)
			std::swap(c[elementIndex(elementSize, getB(n)) + i], c[elementIndex(elementSize, getA(n)) + i]);
	}

	// Sort all pairs in the container based on the b and a values of each pair
	template <typename Container>
	void	sortPairs(Container &c, unsigned int pairSize, unsigned int &comparisons) {
		unsigned int totalPairs = c.size() / pairSize;
		unsigned int elementSize = pairSize / 2;

		// n = pair index: b1, b2, b3, ..., bn
		for (unsigned int n = 1; n <= totalPairs; n++) {
			++comparisons;
			if (bValue(c, elementSize, n) > aValue(c, elementSize, n))
				swapPair(c, elementSize, n);
		}
	}

	// Move every element b but b1 into a temporary container
	template <typename Container>
	void	movePendingElements(Container &c, Container &temp, unsigned int elementSize) {
		unsigned int totalElements = c.size() / elementSize;
		// Move every b but b1 into a temporary container
		for (unsigned int n = 2; n <= totalElements - totalElements / 2; n++)
			pushElement(c, temp, elementSize, getB(n));

		// Remove every b but b1 from the original container
		for (int n = totalElements - totalElements / 2; n >= 2; --n)
			popElement(c, elementSize, getB(n));
	}

	// Insert temporary container into original container
	// Using:	-binary search to determine the <location> of insertion
	// 			-Jacobsthal sequence to determine the <order> of insertion
	template <typename Container>
	void	mergeInsert(Container &c, Container &temp, unsigned int elementSize, unsigned int &comparisons) {
		unsigned int totalElements = temp.size() / elementSize;
		unsigned int previous = 0;
		unsigned int ithJacobsthal = 2;
		unsigned int current = Jacobsthal(ithJacobsthal);
		unsigned int insertedNumbers = 0;

		while (previous < totalElements) {
			unsigned int upper = std::min(current, totalElements);
			unsigned int searchLimit = upper + insertedNumbers + 1;
			for (unsigned int n = upper; n > previous; --n) {
				unsigned int dstN = binarySearch(c, temp, elementSize, n, searchLimit, comparisons);
				insertBefore(temp, c, elementSize, n, dstN);
				++insertedNumbers;
			}

			previous = upper;
			++ithJacobsthal;
			current = Jacobsthal(ithJacobsthal);
		}
	}

	// Recursively sort the container, given the current depth
	/* Following Ford-Johnson's algorithm;
	 * 1. Compare and sort pairs of elements (a, b) at the current depth
	 * 2. Recursively repeat step 1 for the next depth, till no more pairs can be formed
	 * 3. Move every element b but b1 into a temporary container
	 * 4. Insert temporary container into original container using Jacobsthal sequence to determine the order of insertion
	 * 5. Repeat step 3-4 till the recursion is complete
	*/
	template <typename Container>
	void	recursiveSort(Container &c, unsigned int depth, unsigned int &comparisons) {
		unsigned int pairSize = std::pow(2, depth);

		// If no more pairs can be formed, return
		if (c.size() / pairSize == 0)
			return;

		// Step 1
		sortPairs(c, pairSize, comparisons);

		// Step 2
		recursiveSort(c, depth + 1, comparisons);

		// Step 3
		Container temp;
		unsigned int elementSize = pairSize / 2;
		movePendingElements(c, temp, elementSize);

		// Step 4
		mergeInsert(c, temp, elementSize, comparisons);
	}

	// Sort the container using Ford's algorithm and return the time taken to sort in nanoseconds
	template <typename Container>
	std::chrono::nanoseconds	sort(Container &c) {
		unsigned int comparisons = 0;

		auto start = std::chrono::high_resolution_clock::now();
		recursiveSort(c, 1, comparisons);
		auto end = std::chrono::high_resolution_clock::now();

		assert(std::is_sorted(c.begin(), c.end()));
		assert(comparisons <= validateAlgorithm(c.size()));

		return (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start));
	}
}

#endif
