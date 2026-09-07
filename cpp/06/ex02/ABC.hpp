/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:57:10 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/07 11:59:13 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef H_ABC
# define H_ABC

#include <stdint.h>
#include "Base.hpp"

class A: public Base{
	public:
		A();
		~A();
};

class B: public Base{
	public:
		B();
		~B();
};

class C: public Base{
	public:
		C();
		~C();
};

#endif
