/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 11:36:58 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/07 13:16:06 by nmattos       ########   odam.nl         */
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

		Contact(std::string firstname, std::string lastname, std::string nickname,
				std::string phone, std::string secret) {
			this->firstname = firstname;
			this->lastname = lastname;
			this->nickname = nickname;
			this->phone = phone;
			this->secret = secret;
		}

		void viewContact(int index) {
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

		void fullContact() {
			std::cout << "First Name:\t" << firstname << std::endl;
			std::cout << "Last Name:\t" << lastname << std::endl;
			std::cout << "Nickname:\t" << nickname << std::endl;
			std::cout << "Phone:\t\t" << phone << std::endl;
			std::cout << "Darkest Secret:\t" << secret << std::endl;
		}
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
