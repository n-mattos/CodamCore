/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:34:23 by nmattos-          #+#    #+#             */
/*   Updated: 2026/10/13 10:37:36 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

// Process database (csv) file and store parsed data in _data
void BitcoinExchange::_processDatabase(const std::string &dbName) {
	std::ifstream dbFile(dbName.c_str());
    if (!dbFile.is_open())
		throw std::runtime_error("Could not open database file: " + dbName);

	// Read header
	std::string line;
	std::getline(dbFile, line);
	if (line != "date,exchange_rate")
		throw std::invalid_argument("Invalid header in database file: " + dbName);

	// Read and parse each line of the csv file
	while (std::getline(dbFile, line)) {
		std::stringstream lineStream(line);
		std::string date;
		std::getline(lineStream, date, ',');
		std::string exchangeRate;
		std::getline(lineStream, exchangeRate, ',');
		this->_data.insert(std::make_pair(date, std::stof(exchangeRate)));
	}

	dbFile.close();
}

// Validate cells from input file
void BitcoinExchange::_validateInput(const std::string &date, const std::string &bitcoinAmount) {
	// Validate date format (YYYY-MM-DD)
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') // format is YYYY-MM-DD
		throw std::invalid_argument("not a valid date (YYYY-MM-DD) => " + date);

	if (date.substr(0, 4).find_first_not_of("0123456789") != std::string::npos)	// year is numeric
		throw std::invalid_argument("not a valid year => " + date);

	if (std::stoi(date.substr(5, 2)) < 1 || std::stoi(date.substr(5, 2)) > 12)	// month between 1-12
		throw std::invalid_argument("not a valid month => " + date);

	if (std::stoi(date.substr(8, 2)) < 1 || std::stoi(date.substr(8, 2)) > 31)	// day between 1-31
		throw std::invalid_argument("bad input => " + date);

	// Validate bitcoinAmount
	if (bitcoinAmount.empty())
		throw std::invalid_argument("missing bitcoin amount => " + date);
	if (bitcoinAmount.find_first_not_of("0123456789.") != std::string::npos)
		throw std::invalid_argument("not a positive number => " + bitcoinAmount);
	if (bitcoinAmount.find('.') != bitcoinAmount.rfind('.'))
		throw std::invalid_argument("not a number => " + bitcoinAmount);
	if (std::stof(bitcoinAmount) > 1000)
		throw std::invalid_argument("too large a number => " + bitcoinAmount);
}

BitcoinExchange::BitcoinExchange(const std::string &dbName) {
	if (dbName.empty())
        throw std::invalid_argument("Database filename is empty");

	if (std::filesystem::path(dbName).extension() != ".csv")
		throw std::invalid_argument("Database must be a .csv file");

	try {
		this->_processDatabase(dbName);
	} catch (const std::exception& error) {
		std::cerr << "Database error: " << error.what() << std::endl;
		throw;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_data = other._data;
	}

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// Calculate and print results using input
void BitcoinExchange::execute(const std::string &input) {
	if (input.empty())
        throw std::invalid_argument("Input filename is empty");

	if (std::filesystem::path(input).extension() != ".txt")
		throw std::invalid_argument("Input must be a .txt file");

	std::ifstream inputFile(input.c_str());
    if (!inputFile.is_open())
		throw std::runtime_error("Could not open input file: " + input);

	// Read header
	std::string line;
	std::getline(inputFile, line);
	if (line != "date | value")
		throw std::invalid_argument("Invalid header in input file: " + input);

	// Read and parse each line of the csv file
	while (std::getline(inputFile, line)) {
		std::stringstream lineStream(line);
		std::string date;
		std::getline(lineStream, date, '|');
		std::string bitcoinAmount;
		std::getline(lineStream, bitcoinAmount, '|');

		// Remove trailing whitespace from date and leading whitespace from bitcoinAmount
		// (Result of the " | " seperator)
		date.erase(date.find_last_not_of(" \t") + 1);
		bitcoinAmount.erase(0, bitcoinAmount.find_first_not_of(" \t"));

		try {
			// Validate 'date' and 'bitcoinAmount' from inputFile
			_validateInput(date, bitcoinAmount);

			// Process the parsed date and exchange rate
			// upper_bound returns the first element that is greater than the given key
			std::map<std::string, float>::const_iterator rate = this->_data.upper_bound(date);
			if (rate == this->_data.begin()) {
				rate = this->_data.begin();
			} else {
				--rate;
			}

			// Print result
			std::cout
				<< date
				<< " => "
				<< std::stof(bitcoinAmount) * rate->second
			<< std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	inputFile.close();
}
