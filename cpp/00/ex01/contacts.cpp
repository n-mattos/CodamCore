/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contacts.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 11:43:08 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/07 13:14:16 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	search(Phonebook book)
{
	book.viewAllContacts();
	std::string input;
	std::cout << "Which contact do you wish to display?\n>> ";
	if (!std::getline(std::cin, input))
		return ;

	while (1) {
		int index;
		try {
			index = std::stoi(input);
			if (index < 1 || index > 8) {
				std::cout << "Invalid input. Please enter a number between 1-8\n>> ";
				if (!std::getline(std::cin, input))
					return ;
				continue;
			}
		} catch (const std::invalid_argument&) {
			std::cout << "Invalid input. Please enter a number between 1-8\n>> ";
			if (!std::getline(std::cin, input))
				return ;
			continue;
		}
		book.getContact(index - 1).fullContact();
		return ;
	}
}

static std::string	get_input(void)
{
	std::string	input;

	if (!std::getline(std::cin, input))
			exit(1);
	while (input.empty()) {
		std::cout << "Input field cannot be empty\n>> ";
		if (!std::getline(std::cin, input))
			exit(1);
	}
	return (input);
}

Phonebook	add(Phonebook book)
{
	std::cout << "Firstname\n>> ";
	std::string	firstname = get_input();
	std::cout << "Lastname\n>> ";
	std::string	lastname = get_input();
	std::cout << "Nickname\n>> ";
	std::string	nickname = get_input();
	std::cout << "Phone\n>> ";
	std::string	phone = get_input();
	std::cout << "Secret\n>> ";
	std::string	secret = get_input();

	Contact new_contact(firstname, lastname, nickname, phone, secret);
	book.addContact(new_contact);
	return (book);
}
