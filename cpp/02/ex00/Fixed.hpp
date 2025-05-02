/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:01:57 by nmattos           #+#    #+#             */
/*   Updated: 2025/05/02 13:11:16 by nmattos-         ###   ########.fr       */
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

		Fixed &operator=(const Fixed &other);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
