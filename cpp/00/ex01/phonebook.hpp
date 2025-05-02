/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:36:58 by nmattos           #+#    #+#             */
/*   Updated: 2025/04/28 14:41:47 by nmattos-         ###   ########.fr       */
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

		Contact getContact(int index) {
			return (contacts[index]);
		}

		void addContact(Contact contact) {
			contacts[index] = contact;
            index = (index + 1) % 8;
		}

		void viewAllContacts() {
			std::cout << "---------------------------------------------\n";
            for (int i = 0; i < 8; i++) {
                contacts[(i) % 8].viewContact(i + 1);
            }
			std::cout << "---------------------------------------------\n";
        }
};

void		search(Phonebook book);
Phonebook	add(Phonebook book);
