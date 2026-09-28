/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ABC.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/07 11:57:10 by nmattos-      #+#    #+#                 */
/*   Updated: 2026/09/28 11:45:19 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef H_ABC
# define H_ABC

#include <stdint.h>
#include "Base.hpp"

class A: public Base{
	public:
		A();
		A(const A& other);
		A& operator=(const A& other);
		~A();
};

class B: public Base{
	public:
		B();
		B(const B& other);
		B& operator=(const B& other);
		~B();
};

class C: public Base{
	public:
		C();
		C(const C& other);
		C& operator=(const C& other);
		~C();
};

#endif
