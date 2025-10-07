/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:19:34 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/07 11:15:01 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FRAGTRAP
# define H_FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap() override;

		void	attack(const std::string& target) override;
		void	takeDamage(unsigned int amount) override;
		void	beRepaired(unsigned int amount) override;
		void 	highFivesGuys();
};

#endif
