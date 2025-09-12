/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:50:52 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/12 15:14:50 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_WEAPON
#define H_WEAPON
#include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		// Constructors
		Weapon();
		Weapon(std::string type);

		// Deconstructor
		~Weapon();

		// Functions
		std::string const&	getType() const;
		void				setType(std::string type);
};

#endif
