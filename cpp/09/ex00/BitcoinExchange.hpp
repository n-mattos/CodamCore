/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:29:11 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/12 16:26:01 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

// Input doesn't need to be stored. Instead it's instantly calculated on read.
class BitcoinExchange {
	private:
		// std::map to store the exchange rates
		std::map<std::string, float> _data;

		void	_validateInput(const std::string &date, const std::string &bitcoinAmount);
		void	_processDatabase(const std::string &dbName);

	public:
		// Disallow constructor without database parameter
		BitcoinExchange() = delete;
		// explicit prevents automatic conversion of string to object
		explicit BitcoinExchange(const std::string &dbName);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	execute(const std::string &input);
};

#endif
