/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 11:17:48 by nmattos       #+#    #+#                 */
/*   Updated: 2025/04/07 11:28:16 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string	shout(std::string input)
{
	for (size_t i = 0; i < input.length(); i++) {
		input[i] = std::toupper(input[i]);
	}
	return (input);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << shout(argv[1]) << std::endl;
	return (0);
}
