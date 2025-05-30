/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:37:31 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/08 16:05:18 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) 
{
    std::time_t now = std::time(NULL);
	//std::time_t std::time(std::time_t* time);
    std::tm *ltm = std::localtime(&now);
	//std::tm* std::localtime(const std::time_t* time);
    std::cout << "[" << 1900 + ltm->tm_year
              << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
              << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}

/*
struct tm {
    int tm_sec;   Sekundy (0-60, gdzie 60 oznacza sekundę przestępną)
    int tm_min;   Minuty (0-59)
    int tm_hour;  Godziny (0-23)
    int tm_mday;  Dzień miesiąca (1-31)
    int tm_mon;   Miesiąc (0-11, gdzie 0 = styczeń, 11 = grudzień)
    int tm_year;  Rok od 1900 (np. 125 oznacza rok 2025)
    int tm_wday;  Dzień tygodnia (0-6, gdzie 0 = niedziela)
    int tm_yday;  Dzień roku (0-365, gdzie 0 = 1 stycznia)
    int tm_isdst; Flaga czasu letniego (>0 oznacza czas letni, 0 oznacza brak, <0 brak informacji)
};
*/

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) //lista inicjalizacyjna
{
	//ciało konstruktora
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) 
{
    return _nbAccounts;
}

int Account::getTotalAmount(void) 
{
    return _totalAmount;
}

int Account::getNbDeposits(void) 
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) 
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) 
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";
    if (withdrawal > _amount) {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

