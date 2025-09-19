/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:34:20 by nmattos           #+#    #+#             */
/*   Updated: 2025/09/19 10:16:52 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CLAPTRAP
# define H_CLAPTRAP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hp = 10;
		int			_ep = 10;
		int			_at = 0;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
