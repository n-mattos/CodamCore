/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:43 by nmattos-          #+#    #+#             */
/*   Updated: 2025/04/23 14:44:29 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int	value;
		static const int fractionalbit = 8;
	public:
		Fixed() : value(0) {
			std::cout << "Default constructor called" << std::endl;
		}

		Fixed(const Fixed &other) {
			std::cout << "Copy constructor called" << std::endl;
			*this = other;
		}

		Fixed(const int val) : value(val) {
			std::cout << "Int constructor called" << std::endl;
			//
		}

		Fixed(const float val) : value(val) {
			std::cout << "Float constructor called" << std::endl;
		}

		// Copy assignment operator overload
		// Copies the value of the copied object.
		Fixed &operator=(const Fixed &other) {
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &other)
				this->value = other.getRawBits();
			return (*this);
		}

		~Fixed() {
			std::cout << "Destructor called" << std::endl;
		}

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// Insertion operator overload;
// Inserts a floating-point of the fixed-point number into
// the output stream object passed as a parameter.
std::ostream &operator<<(std::ostream &out, const Fixed num) {
	out << num.toFloat();
	return (out);
}
