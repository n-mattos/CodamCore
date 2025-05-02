/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:36:21 by nmattos           #+#    #+#             */
/*   Updated: 2025/04/28 11:04:53 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
