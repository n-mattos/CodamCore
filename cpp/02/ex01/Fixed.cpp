/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:57 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/02 13:17:44 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int val) : value(val) {
	std::cout << "Int constructor called" << std::endl;
	//
}

Fixed::Fixed(const float val) : value(val) {
	std::cout << "Float constructor called" << std::endl;
}

// Copy assignment operator overload
// Copies the value of the copied object.
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

// bit shift
float	Fixed::toFloat(void) const {
	return static_cast<float>(value / (1 << fractionalbit));
}

int		Fixed::toInt(void) const {
	return (value >> fractionalbit);
}

std::ostream &operator<<(std::ostream &out, const Fixed num) {
	out << num.toFloat();
	return (out);
}
