/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account->cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student->codam->nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 14:55:19 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/04/13 08:18:09 by nmattos       ########   odam->nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <functional>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Default Constructor
Account::Account() {};

// Constructor w/ an argument (deposit)
Account::Account(int initial_deposit) {
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_nbAccounts += 1;
	this->_totalAmount += this->_amount;

	this->_displayTimestamp();
	std::cout << "index:"		<< this->_accountIndex
			  << ";amount:"		<< checkAmount()
			  << ";created"		<< std::endl;
}

// Destructor w/ print
Account::~Account(void) {
	this->_displayTimestamp();
	std::cout << "index:"		<< this->_accountIndex
			  << ";amount:"		<< checkAmount()
			  << ";closed"		<< std::endl;
}

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

// Prints the combined info of all existing accounts
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:"	 << getNbAccounts()
			  << ";total:"		 << getTotalAmount()
			  << ";deposits:"	 << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

// Deposits (int deposit) into the account
void Account::makeDeposit(int deposit) {
	this->_displayTimestamp();
	std::cout << "index:"		<< this->_accountIndex
			  << ";p_amount:"	<< checkAmount()
			  << ";deposit:"	<< deposit;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;

	std::cout << ";amount:"		 << checkAmount()
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

// Withdraws (int withdrawal) from the account
bool Account::makeWithdrawal(int withdrawal) {
	this->_displayTimestamp();
	std::cout << "index:"		<< this->_accountIndex
			  << ";p_amount:"	<< checkAmount()
			  << ";withdrawal:";

	if (withdrawal > checkAmount()) {
		std::cout << "refused" << std::endl;
		return (false);
	} else {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;

		std::cout << withdrawal
				  << ";amount:"		 	<< checkAmount()
			  	  << ";nb_withdrawals:"	<< this->_nbWithdrawals
			  	  << std::endl;
		return (true);
	}
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

// Prints the info of the account
void Account::displayStatus(void) const {
	this->_displayTimestamp();
	std::cout << "index:"		 << this->_accountIndex
			  << ";amount:"		 << checkAmount()
			  << ";deposits:"	 << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

// Prints the current time
// Ensures data (except for year) is printed as 2 digits. (Using setfill / setw)
void Account::_displayTimestamp( void )
{
	// std::cout << "[19920104_091532] ";
	// return ;
	time_t t = std::time(NULL);
	struct tm* now = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900)								// Year
			  << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)		// Month
			  << std::setfill('0') << std::setw(2) << now->tm_mday << "_"	// Day
			  << std::setfill('0') << std::setw(2) << now->tm_hour			// Hour
			  << std::setfill('0') << std::setw(2) << now->tm_min			// Minute
			  << std::setfill('0') << std::setw(2) << now->tm_sec << "] ";	// Second
}
