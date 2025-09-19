/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:57 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 09:13:13 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	value = other.value;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	value = roundf(val * (1 << fractionalbit));
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(val * (1 << fractionalbit));
}

// Copy assignment operator overload
// Copies the value of the copied object.
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.value;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	return (value);
}

void	Fixed::setRawBits(int const raw) {
	value = raw;
}

// bit shift
float	Fixed::toFloat(void) const {
	return (static_cast<float>(value) / (1 << fractionalbit));
}

int		Fixed::toInt(void) const {
	return (value >> fractionalbit);
}

std::ostream &operator<<(std::ostream &out, const Fixed &num) {
	out << num.toFloat();
	return (out);
}
