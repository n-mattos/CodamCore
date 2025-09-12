/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:38:51 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/12 15:16:16 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

static std::string	replace_string(std::string line,
								   const std::string s1,
								   const std::string s2)
{
	size_t	pos = 0;

	if (s1.empty())
		return (line);
	while ((pos = line.find(s1, pos)) != std::string::npos) {
        line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        pos += s2.length();
    }
	return (line);
}

int	sed(int argc, char *argv[]) {
	// CHECK INPUT
	if (argc != 4) {
		std::cerr << ERROR_ARG << std::endl << USAGE << std::endl;
		return (1);
	}

	// OPEN OLD
	std::ifstream file(argv[FILENAME]);
	if (!file.is_open()) {
		std::cerr << ERROR_FILE << std::endl;
		return (1);
	}

	// CREATE NEW
	std::ofstream new_file(std::string(argv[FILENAME]) + ".replace");
	if (!new_file.is_open()) {
		std::cerr << ERROR_FILE << std::endl;
		return (1);
	}

	// READ OLD, REPLACE, WRITE NEW
	std::string line;
	while (std::getline(file, line))
		new_file << replace_string(line, argv[TO_REPLACE], argv[REPLACEMENT]) << "\n";

	// CLOSE FILES
	file.close();
	new_file.close();
	return (0);
}
