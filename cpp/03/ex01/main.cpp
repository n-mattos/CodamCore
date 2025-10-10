/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:01:50 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 12:51:41 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	std::cout << "ClapTrap Tests:" << "\n";
	ClapTrap bert = ClapTrap("bert");
	bert.attack("bob");
	bert.takeDamage(3);
	bert.beRepaired(2);

	std::cout << "\n" << "ScavTrap Tests:" << "\n";
	ScavTrap alice = ScavTrap("alice");
	alice.attack("angie");
	alice.takeDamage(3);
	alice.beRepaired(2);
	alice.guardGate();

	std::cout << "\n" << "Deconstructors:" << "\n";
	return (0);
}
