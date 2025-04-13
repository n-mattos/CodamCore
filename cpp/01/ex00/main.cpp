/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 09:47:05 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/13 09:59:35 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	randomChump("Alice");

	Zombie *bob = newZombie("Bob");
	bob->announce();
	delete bob;
}
