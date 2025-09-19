/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:34:06 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/19 10:04:01 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y) {
	// std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
}

Point &Point::operator=(const Point &other) {
	// Can't assign to const members (do nothing)
	(void)other; // Suppress unused parameter warning
    return (*this);
}

Point::~Point() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed Point::getx() const {
	return (x);
}

Fixed Point::gety() const {
	return (y);
}

/**
 * Cross product for 2D vectors
 *
 * The sign of the cross product tells us
 * 	-the relative orientation of {other} with respect to {this}
 * Negative result = clockwise
 * Positive result = counterclockwise
 */
Fixed Point::crossproduct(const Point &other) const {
	// (Ax * By - Ay * Bx)
	return (x * other.y - y * other.x);
}
