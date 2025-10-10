/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:18:56 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/10 12:52:06 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	std::cout << "ClapTrap Tests:" << "\n";
	ClapTrap bert = ClapTrap("bert");
	bert.attack("bob");
	bert.takeDamage(3);
	bert.beRepaired(2);

	std::cout << "\n" << "ScavTrap Tests:" << "\n";
	ScavTrap alice = ScavTrap("alice");
	alice.attack("angie");
	alice.takeDamage(7);
	alice.beRepaired(5);
	alice.guardGate();

	std::cout << "\n" << "FragTrap Tests:" << "\n";
	FragTrap charles = FragTrap("charles");
	charles.attack("chris");
	charles.takeDamage(14);
	charles.beRepaired(9);
	charles.highFivesGuys();

	std::cout << "\n" << "DiamondTrap Tests:" << "\n";
	DiamondTrap dan = DiamondTrap("dan");
	dan.attack("denise");
	dan.takeDamage(14);
	dan.beRepaired(9);
	dan.whoAmI();

	std::cout << "\n" << "Deconstructors:" << "\n";
	return (0);
}
