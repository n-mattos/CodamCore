/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:58:37 by nmattos-          #+#    #+#             */
/*   Updated: 2025/10/21 11:47:16 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main() {
	const Animal* none = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nTypes:" << "\n";
	std::cout << none->getType() << " " << "\n";
	std::cout << dog->getType() << " " << "\n";
	std::cout << cat->getType() << " " << "\n";

	std::cout << "\nSounds:" << "\n";
	none->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << "\nDeleting animals:" << "\n";
	delete none;
	std::cout << "\n";
	delete dog;
	std::cout << "\n";
	delete cat;

	std::cout << "\n--- Wrong Animals ---\n";
	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << " " << "\n";
	wrong->makeSound();

	delete wrong;

	return 0;
}
