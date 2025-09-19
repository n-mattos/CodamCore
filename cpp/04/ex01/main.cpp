/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:58:37 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 13:05:42 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main() {
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "---------------------" << "\n";
	delete dog;
	delete cat;

	Animal* animals[4];
	std::cout << "---------------------" << "\n";
	for (int i = 0; i < 2; i++) animals[i] = new Dog();
	std::cout << "---------------------" << "\n";
	for (int i = 2; i < 4; i++) animals[i] = new Cat();
	std::cout << "---------------------" << "\n";
	for (int i = 0; i < 4; i++) animals[i]->makeSound();
	std::cout << "---------------------" << "\n";
	for (int i = 0; i < 4; i++) delete animals[i];

	return 0;
}
