/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:57:22 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/08 12:13:22 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_ARRAY
# define H_ARRAY

#include <iostream>

template <typename T> class Array {
	private:
		unsigned int	length;
		T				*arr;

		// Prevent redundant code in copy constructor and assignment operator overload
		Array &copy(const Array &other) {
			length = other.length;
			arr = new T[length];
			for (unsigned int i = 0; i < length; i++) {
				arr[i] = other.arr[i];
			}
			return (*this);
		}

	public:
		// No param
		// Creates empty array
		Array() {
			length = 0;
			arr = new T[0];
		}

		// unsigned int n as param
		Array(unsigned int n) {
			length = n;
			arr = new T[length];
		}

		// Copy constructor
		Array(const Array &other) {
			*this = copy(other);
		}

		// Assignment operator overload
		Array &operator=(const Array &other) {
			if (this != &other) {
				delete[] arr;

				*this = copy(other);
			}
			return (*this);
		}

		// Subscript operator overload
		T &operator[](unsigned int index) {
			if (index >= length || index < 0) {
				throw std::out_of_range("Index out of bounds");
			}
			return (arr[index]);
		}

		// Return size of the array
		unsigned int size() const {
			return (length);
		}

		// Log the array
		void logArray() {
			for (unsigned int i = 0; i < length; i++) {
				std::cout << arr[i] << "\n";
			}
		}

		~Array() {
			delete[] arr;
		}
};

#endif
