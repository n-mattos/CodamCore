/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/21 11:01:57 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/21 11:22:54 by nmattos       ########   odam.nl         */
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

		Fixed(const Fixed &other) : value(other.value) {
			std::cout << "Copy constructor called" << std::endl;
		}

		Fixed &operator=(const Fixed &other) {
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &other) {
				this->value = getRawBits();
			}
			return *this;
		}

		~Fixed() {
			std::cout << "Destructor called" << std::endl;
		}

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
