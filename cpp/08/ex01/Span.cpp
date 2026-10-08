/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:58:14 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/08 12:35:15 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span() : _N(0) {}

Span::Span(unsigned int N): _N(N) {}

Span::Span(const Span& other) : _N(other._N), _vector(other._vector) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_N = other._N;
		_vector = other._vector;
	}

	return (*this);
}

Span::~Span() {}

// Add multiple numbers using iterators
void Span::addMultiple(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_vector.size() + std::distance(begin, end) > _N) {
		throw Span::out_of_range();
	}

	// insert range of unmbers at the end of the vector
	// (_vector.assign() replaces the entire vector)
	_vector.insert(_vector.end(), begin, end);
}

// Add a single number to the back of the vector
void Span::addNumber(int value) {
	if (_vector.size() >= _N) {
		throw Span::out_of_range();
	}

	_vector.push_back(value);
}

// Sort the vector and find the shortest span in adjacent numbers
unsigned int Span::shortestSpan() {
	// Sort the vector
	std::vector<int> sorted_vector = _vector;
	std::sort(sorted_vector.begin(), sorted_vector.end());

	// Remove dupes
	sorted_vector.erase(
		std::unique(sorted_vector.begin(), sorted_vector.end()), // point to new end of vector
		sorted_vector.end() // end of vector
	);

	if (sorted_vector.empty() || sorted_vector.size() == 1) {
		throw Span::no_span();
	}

	// Compare adjacent numbers
	// vector is sorted, so the shortest span is always between adjacent numbers
	std::vector<int>::iterator it = sorted_vector.begin();
	unsigned int shortest_span = UINT_MAX;
	while (it != sorted_vector.end() - 1) {
		unsigned int span = *(it + 1) - *it;
		if (span < shortest_span) {
			shortest_span = span;
		}
		it++;
	}
	return (shortest_span);
}

// Sort the vector and compare the first and last number
unsigned int Span::longestSpan() {
	// Sort the vector
	std::vector<int> sorted_vector = _vector;
	std::sort(sorted_vector.begin(), sorted_vector.end());

	// Remove dupes
	sorted_vector.erase(
		std::unique(sorted_vector.begin(), sorted_vector.end()), // point to new end of vector
		sorted_vector.end() // end of vector
	);

	if (sorted_vector.empty() || sorted_vector.size() == 1) {
		throw Span::no_span();
	}

	// Compare the first and last number
	return (sorted_vector.back() - sorted_vector.front());
}

unsigned int Span::getSize() {
	return (_vector.size());
}

int Span::getValueAtIndex(unsigned int index) {
	if (index >= _vector.size()) {
		throw std::out_of_range("Index out of range");
	}

	return (_vector[index]);
}

std::ostream& operator<<(std::ostream& out, const Span& span) {
	out << "Span: [";
	Span& non_const_span = const_cast<Span&>(span);

	for (size_t i = 0; i < non_const_span.getSize(); i++) {
		out << non_const_span.getValueAtIndex(i);
		if (i != non_const_span.getSize() - 1) {
			out << ", ";
		}
	}

	out << "]";
	return out;
}
