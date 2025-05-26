/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:12:33 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 15:31:53 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_DOG
# define H_DOG

#include "Animal.hpp"

class Dog : virtual public Animal
{
	protected:
		std::string	type;

	public:
		Dog();
		~Dog();

		void	makeSound() const override;
};

#endif
