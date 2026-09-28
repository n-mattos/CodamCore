/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ABC.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/07 11:59:20 by nmattos-      #+#    #+#                 */
/*   Updated: 2026/09/28 11:46:20 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"

// A
A::A() {}

A::A(const A& other) {
	(void)other;
}

A& A::operator=(const A& other) {
	(void)other; return (*this);
}

A::~A() {}

// B
B::B() {}

B::B(const B& other) {
	(void)other;
}

B& B::operator=(const B& other) {
	(void)other; return (*this);
}

B::~B() {}

// C
C::C() {}

C::C(const C& other) {
	(void)other;
}

C& C::operator=(const C& other) {
	(void)other; return (*this);

}

C::~C() {}
