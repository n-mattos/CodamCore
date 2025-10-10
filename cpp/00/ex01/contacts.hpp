/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:59:20 by nmattos-          #+#    #+#             */
/*   Updated: 2025/08/25 12:01:13 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
	public:
		Contact();
		Contact(std::string firstname,
				std::string lastname,
				std::string nickname,
				std::string phone,
				std::string secret);

		void viewContact(int index);
		void fullContact();
};
