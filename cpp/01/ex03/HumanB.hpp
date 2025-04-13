/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 17:01:36 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/13 17:22:12 by nmattos       ########   odam.nl         */
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
		std::string	getName(void)	const		{return (this->name);}
		std::string	getWeapon(void) const		{return (this->weapon->getType());}
		void		setWeapon(Weapon &weapon)	{this->weapon = &weapon;}
		void		attack(void);
};
