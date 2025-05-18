/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/18 13:34:20 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/18 13:51:45 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CLAPTRAP
# define H_CLAPTRAP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			hp = 10;
		int			ep = 10;
		int			at = 0;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
