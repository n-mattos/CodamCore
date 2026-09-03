/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:19:17 by nmattos-          #+#    #+#             */
/*   Updated: 2026/09/03 11:18:03 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_SCALAR
# define H_SCALAR

#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();

		static void		printPseudo(std::string input);
		static void		printChar(std::string input);
		static void		printInt(std::string input);
		static void		printFloat(std::string input);
		static void		printDouble(std::string input);
		static bool		atoi(const char *nptr, int &value);
		static bool		calcInt(const char *nptr, int &value);
		static bool		calcFloat(const char *nptr, float &value);
		static bool		calcDouble(const char *nptr, double &value);
		static bool		isChar(std::string input);
		static bool		isInt(std::string input);
		static bool		isFloat(std::string input);
		static bool		isDouble(std::string input);

	public:
		static void	convert(std::string input);
};

#endif
