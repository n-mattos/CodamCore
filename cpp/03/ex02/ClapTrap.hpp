/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:14:07 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 11:19:06 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CLAPTRAP
# define H_CLAPTRAP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		std::string	name;
		int			hp = 10;
		int			ep = 10;
		int			at = 0;

		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
