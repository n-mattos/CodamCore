/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 11:34:06 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/08 12:31:53 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	// Create vectors;
	Point vectorA((c.getx() - a.getx()).toFloat(), (c.gety() - a.gety()).toFloat());
}

Point::Point() {
	this->setx(0);
	this->sety(0);
}

Point::Point(const float x, const float y) {
	this->setx(x);
	this->sety(y);
}

Point::Point(const Point &other) {
	*this = other;
}

Point &Point::operator=(const Point &other) {
	if (this != &other)
	{
		this->setx(other.getx());
		this->sety(other.gety());
	}
	return (*this);
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

Fixed Point::getx() const {
	return (this->x);
}

void	Point::setx(int const x) {
	this->x = x;
}

Fixed Point::gety() const {
	return (this->y);
}

void	Point::sety(int const y) {
	this->y = y;
}