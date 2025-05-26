/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:18:56 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 14:35:17 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	std::cout << "ClapTrap Tests:" << std::endl;
	ClapTrap bert = ClapTrap("bert");
	bert.attack("bob");
	bert.takeDamage(3);
	bert.beRepaired(2);

	std::cout << std::endl << "ScavTrap Tests:" << std::endl;
	ScavTrap alice = ScavTrap("alice");
	alice.attack("angie");
	alice.takeDamage(7);
	alice.beRepaired(5);
	alice.guardGate();

	std::cout << std::endl << "FragTrap Tests:" << std::endl;
	FragTrap charles = FragTrap("charles");
	charles.attack("chris");
	charles.takeDamage(14);
	charles.beRepaired(9);
	charles.highFivesGuys();

	std::cout << std::endl << "DiamondTrap Tests:" << std::endl;
	DiamondTrap dan = DiamondTrap("dan");
	dan.attack("denise");
	dan.takeDamage(14);
	dan.beRepaired(9);

	std::cout << std::endl << "Deconstructors:" << std::endl;
	return (0);
}
