/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 16:55:12 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/13 17:22:07 by nmattos       ########   odam.nl         */
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
		std::string	getName(void)	const		{return (this->name);}
		std::string	getWeapon(void) const		{return (this->weapon->getType());}
		void		setWeapon(Weapon &weapon)	{this->weapon = &weapon;}
		void		attack(void);
};
