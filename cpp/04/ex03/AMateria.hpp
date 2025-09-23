/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:20:04 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/23 11:11:32 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_AMATERIA
# define H_AMATERIA

#include <string>
#include <iostream>

class ICharacter;

class AMateria {
	protected:
		std::string _type;

	public:
		AMateria(std::string const& type);
		virtual	~AMateria();

		std::string const& getType() const;	// Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

class Ice : public AMateria {
	public:
		Ice() : AMateria("ice") {}

    AMateria* clone() const override;
};

class Cure : public AMateria {
	public:
		Cure() : AMateria("cure") {}

    AMateria* clone() const override;
};

#endif