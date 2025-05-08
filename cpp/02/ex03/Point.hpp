/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 11:33:02 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/08 12:30:48 by nmattos       ########   odam.nl         */
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
		void	setx(int const x);
		Fixed	gety() const;
		void	sety(int const y);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
