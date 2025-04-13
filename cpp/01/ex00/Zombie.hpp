/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 09:33:29 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/13 09:57:46 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		// Constructors
		Zombie() : name("") {}
		Zombie(std::string name) {this->name = name;}

		// Deconstructor
		~Zombie(void);

		// Functions
		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
