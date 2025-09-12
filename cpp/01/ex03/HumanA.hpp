/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:55:12 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/12 15:14:58 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		// Constructors
		HumanA(std::string name, Weapon &weapon);

		// Deconstructor
		~HumanA();

		// Functions
		std::string	getName()	const;
		std::string	getWeapon() const;
		void		setWeapon(Weapon &weapon);
		void		attack();
};
