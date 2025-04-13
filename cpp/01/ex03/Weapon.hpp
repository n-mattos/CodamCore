/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 16:50:52 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/13 17:10:47 by nmattos       ########   odam.nl         */
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
		Weapon() : type("") {}
		Weapon(std::string type) {this->type = type;}

		// Deconstructor
		~Weapon();

		// Functions
		std::string	getType(void) const			{return (this->type);}
		void		setType(std::string type)	{this->type = type;}
};

#endif
