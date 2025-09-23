/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:19:10 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/23 12:19:54 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// Own tests
	std::cout << "-----My tests-----\n";

	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());

	ICharacter* me2 = new Character("me");
	AMateria*	ice;
	ice = src2->createMateria("ice");
	me2->equip(ice);

	me2->use(3, *me2);
	me2->use(2, *me2);
	me2->use(0, *me2);

	me2->unequip(4);
	me2->unequip(0);
	delete ice;

	me2->use(0, *me2);

	delete me2;
	delete src2;

	return 0;
}
