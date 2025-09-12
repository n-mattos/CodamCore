/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:01:36 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/12 11:50:06 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		// Constructors
		HumanB(std::string name);

		// Deconstructor
		~HumanB();

		// Functions
		std::string	getName(void)	const;
		std::string	getWeapon(void) const;
		void		setWeapon(Weapon &weapon);
		void		attack(void);
};
