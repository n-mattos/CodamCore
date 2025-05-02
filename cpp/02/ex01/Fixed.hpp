/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:43 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/02 13:17:40 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

		// Copy assignment operator overload
		// Copies the value of the copied object.
		Fixed &operator=(const Fixed &other);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// Insertion operator overload;
// Inserts a floating-point of the fixed-point number into
// the output stream object passed as a parameter.
std::ostream &operator<<(std::ostream &out, const Fixed num);
