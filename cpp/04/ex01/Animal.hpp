/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:00:03 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 12:41:46 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_ANIMAL
# define H_ANIMAL

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
};

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif
