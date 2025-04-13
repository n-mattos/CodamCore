/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 09:47:05 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/13 10:11:31 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 4;
	Zombie *horde = zombieHorde(N, "Grunt");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	delete[] horde;
}
