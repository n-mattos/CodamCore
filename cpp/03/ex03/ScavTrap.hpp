/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:18:50 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 14:30:19 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_SCAVTRAP
# define H_SCAVTRAP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		std::string	name;
		int			hp;
		int			ep;
		int			at;

		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void 	guardGate();
};

#endif
