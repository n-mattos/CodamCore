/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:36:21 by nmattos           #+#    #+#             */
/*   Updated: 2025/07/29 14:00:06 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact Phonebook::getContact(int index)
{
	return (contacts[index]);
}

void Phonebook::addContact(Contact contact)
{
	contacts[index] = contact;
	index = (index + 1) % 8;
}

void	Phonebook::viewAllContacts()
{
	std::cout << "---------------------------------------------\n";
	for (int i = 0; i < 8; i++) {
		contacts[(i) % 8].viewContact(i + 1);
	}
	std::cout << "---------------------------------------------\n";
}

int	main(void)
{
	Phonebook	book;
	std::string	input;

	while (1) {
		std::cout << "> ";
		if (!std::getline(std::cin, input))
			return (1);
		if (input == "ADD")
			book = add(book);
		else if (input == "SEARCH")
			search(book);
		else if (input == "EXIT")
			return (0);
		else
			std::cout << GUIDE;
	}
	return (0);
}
