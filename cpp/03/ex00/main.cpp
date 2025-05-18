/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/18 13:51:51 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/18 14:02:31 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap bert = ClapTrap("bert");

	bert.attack("bob");
	bert.takeDamage(3);
	bert.beRepaired(2);

	return (0);
}
