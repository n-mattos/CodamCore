/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:36:58 by nmattos           #+#    #+#             */
/*   Updated: 2025/07/29 14:00:43 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#define GUIDE "Please type one of the following commands:\n| ADD | SEARCH | EXIT |\n"

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
	public:
		Contact() : firstname(""), lastname(""), nickname(""), phone(""), secret("") {}
		Contact(std::string firstname,
				std::string lastname,
				std::string nickname,
				std::string phone,
				std::string secret);

		void viewContact(int index);
		void fullContact();
};

class Phonebook
{
	private:
		Contact contacts[8];
		int		index;
	public:
		Phonebook() : index(0) {}

		Contact getContact(int index);
		void addContact(Contact contact);
		void viewAllContacts();
};

void		search(Phonebook book);
Phonebook	add(Phonebook book);
