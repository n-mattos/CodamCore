/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:37:49 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 10:04:06 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * Run bsp algorithm to determine whether a point is in a triangle.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	// Calculate edge vectors
	Point vectorAB((b.getx() - a.getx()).toFloat(), (b.gety() - a.gety()).toFloat());
	Point vectorBC((c.getx() - b.getx()).toFloat(), (c.gety() - b.gety()).toFloat());
	Point vectorCA((a.getx() - c.getx()).toFloat(), (a.gety() - c.gety()).toFloat());

	// Calculate Point to Vertex vectors
	Point vectorAP((point.getx() - a.getx()).toFloat(), (point.gety() - a.gety()).toFloat());
	Point vectorBP((point.getx() - b.getx()).toFloat(), (point.gety() - b.gety()).toFloat());
	Point vectorCP((point.getx() - c.getx()).toFloat(), (point.gety() - c.gety()).toFloat());

	// Calculate cross products
	Fixed cross1 = vectorAB.crossproduct(vectorAP);
	Fixed cross2 = vectorBC.crossproduct(vectorBP);
	Fixed cross3 = vectorCA.crossproduct(vectorCP);

	// Check if point is inside the triangle
	// The point is inside the triangle if it is on the same side of all edges
	//		-> [same sign (positive or negative)]
	return ((cross1 > 0 && cross2 > 0 && cross3 > 0)
		 || (cross1 < 0 && cross2 < 0 && cross3 < 0));
}
