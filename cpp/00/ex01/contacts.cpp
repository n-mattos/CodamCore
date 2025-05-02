/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:43:08 by nmattos           #+#    #+#             */
/*   Updated: 2025/04/28 11:05:09 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(std::string firstname, std::string lastname, std::string nickname,
				 std::string phone, std::string secret) {
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phone = phone;
	this->secret = secret;
}

void Contact::viewContact(int index) {
	auto formatField = [](const std::string& field) -> std::string {
		if (field.length() > 10)
			return field.substr(0, 9) + ".";
		else
			return std::string(10 - field.length(), ' ') + field;
	};
	std::cout << "|"
			  << formatField(std::to_string(index)) << "|"
			  << formatField(firstname) << "|"
			  << formatField(lastname) << "|"
			  << formatField(nickname) << "|" << std::endl;
}

void Contact::fullContact() {
	std::cout << "First Name:\t" << firstname << std::endl;
	std::cout << "Last Name:\t" << lastname << std::endl;
	std::cout << "Nickname:\t" << nickname << std::endl;
	std::cout << "Phone:\t\t" << phone << std::endl;
	std::cout << "Darkest Secret:\t" << secret << std::endl;
}

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
	std::cout << "New contact has been added\n";

	Contact new_contact(firstname, lastname, nickname, phone, secret);
	book.addContact(new_contact);
	return (book);
}
