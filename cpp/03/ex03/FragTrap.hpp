/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:19:34 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 14:40:56 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FRAGTRAP
# define H_FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		std::string	name;
		int			hp;
		int			ep;
		int			at;

		FragTrap();
		FragTrap(std::string name);
		~FragTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void 	highFivesGuys(void);
};

#endif
