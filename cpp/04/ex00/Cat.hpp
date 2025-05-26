/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:12:07 by nmattos-          #+#    #+#             */
/*   Updated: 2025/05/26 15:31:51 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CAT
# define H_CAT

#include "Animal.hpp"

class Cat : virtual public Animal
{
	protected:
		std::string	type;

	public:
		Cat();
		~Cat();

		void	makeSound() const override;
};

#endif
