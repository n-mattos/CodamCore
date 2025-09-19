/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:33:02 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/19 10:04:16 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);

		Point &operator=(const Point &other);

		~Point();

		Fixed	getx() const;
		Fixed	gety() const;
		Fixed	crossproduct(const Point &other) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
