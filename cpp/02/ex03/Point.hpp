/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 11:33:02 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/18 13:29:55 by nmattos       ########   odam.nl         */
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
		void	setx(Fixed const x);
		Fixed	gety() const;
		void	sety(Fixed const y);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
