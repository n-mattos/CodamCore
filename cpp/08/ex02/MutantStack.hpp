/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 13:36:32 by nmattos-      #+#    #+#                 */
/*   Updated: 2026/10/10 11:41:58 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_MUTANTSTACK
# define H_MUTANTSTACK

#include <stack>

template <class T>

class MutantStack : public std::stack<T> {
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

		iterator begin() {
			return (this->c.begin());
		}

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
