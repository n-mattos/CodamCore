/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 10:59:50 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/05 12:05:58 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed 			a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "My own tests;" << std::endl;
	Fixed	c(5);
	Fixed	d(7);
	Fixed	e(12);

	std::cout << c + d << "\t| 5 + 7" << std::endl;
	std::cout << c - d << "\t| 5 - 7" << std::endl;
	std::cout << c * d << "\t| 5 * 7" << std::endl;
	std::cout << e / c << "\t| 12 / 5" << std::endl;

	std::cout << Fixed::max(c, d) << "\t| max(5, 7)" << std::endl;
	std::cout << Fixed::min(c, d) << "\t| min(5, 7)" << std::endl;

	return 0;
}
