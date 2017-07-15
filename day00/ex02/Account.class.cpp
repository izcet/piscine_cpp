/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:17:47 by irhett            #+#    #+#             */
/*   Updated: 2017/07/05 21:44:37 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int			Account::_nbAccounts = 0;
int			Account::_totalAmount = 0;
int			Account::_totalNbDeposits = 0;
int			Account::_totalNbWithdrawals = 0;

Account::Account(void) :
	_accountIndex(getNbAccounts()),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::Account(int initial_deposit) :
	_accountIndex(getNbAccounts()),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

int			Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int			Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int			Account::getNbDeposits(void)
{
	return	(_totalNbDeposits);
}

int			Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void		Account::_displayTimestamp(void)
{
	time_t      theTime = time(NULL);
	struct tm   *aTime = localtime(&theTime);
	char        s[32];

	strftime(s, sizeof(s), "[%Y%d%m_%H%M%S] ", aTime);
	std::cout << s;
}

void		Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();

	this->_nbDeposits++;
	_totalNbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();

	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount + withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;

	return true;
}

int			Account::checkAmount(void)		const
{
	return _amount;
}

void		Account::displayStatus(void)	 const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void		Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}
