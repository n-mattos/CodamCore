/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:12:07 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/19 12:52:08 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CAT
# define H_CAT

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		~Cat();

		void	makeSound() const override;
};

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();

		void	makeSound() const override;
};

#endif
