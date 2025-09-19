/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:58:37 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 12:46:39 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main() {
	const Animal* none = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " " << "\n";
	std::cout << cat->getType() << " " << "\n";

	none->makeSound();
	cat->makeSound();
	dog->makeSound();

	delete none;
	delete dog;
	delete cat;

	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << " " << "\n";
	wrong->makeSound();

	delete wrong;

	return 0;
}
