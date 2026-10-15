/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:36:32 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/15 11:42:34 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_MUTANTSTACK
# define H_MUTANTSTACK

#include <stack>

template <class T> class MutantStack : public std::stack<T> {
	public:
		// Typedefs for iterator types
		// (To match given main.cpp)
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack() : std::stack<T>() {}

		MutantStack(const std::stack<T> &src) : std::stack<T>(src) {}

		MutantStack &operator=(const std::stack<T> &src) {
			if (this != &src)
				std::stack<T>::operator=(src);
			return (*this);
		}

		~MutantStack() {}

		// 'c' is the underlying container of std::stack, which is protected
		// We can use it to access begin() and end()
		// Which allows us to iterate over the stack

		// top of stack
		iterator begin() {
			return (this->c.begin());
		}

		// bottom of stack
		iterator end() {
			return (this->c.end());
		}

		const_iterator begin() const {
			return (this->c.begin());
		}

		const_iterator end() const {
			return (this->c.end());
		}
};

#endif
