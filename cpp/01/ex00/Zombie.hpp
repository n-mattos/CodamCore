/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:33:29 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/12 15:11:19 by nmattos-         ###   ########.fr       */
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
		Zombie();
		Zombie(std::string name);

		// Deconstructor
		~Zombie();

		// Functions
		void	announce() const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
