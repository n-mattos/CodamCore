/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 11:33:14 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/08 11:33:14 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	value;
		static const int fractionalbit = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int val);
		Fixed(const float val);

		// Copy assignment overload
		Fixed &operator=(const Fixed &other);
		// Comparison overloads
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const ;
		bool operator>=(const Fixed &other) const ;
		bool operator<=(const Fixed &other) const ;
		bool operator==(const Fixed &other) const ;
		bool operator!=(const Fixed &other) const ;
		// Arithmetic overloads
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		// In-/Decrement overloads
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		// Max/Min overloads
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);


		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &num);
