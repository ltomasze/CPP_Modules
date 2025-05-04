/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:37:31 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/04 15:47:19 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
### Plan implementacji `Account.cpp`

1. **Statyczne zmienne:**
   - `_nbAccounts`: liczba kont.
   - `_totalAmount`: całkowita suma środków na wszystkich kontach.
   - `_totalNbDeposits`: całkowita liczba wpłat.
   - `_totalNbWithdrawals`: całkowita liczba wypłat.

2. **Konstruktor i destruktor:**
   - Konstruktor inicjalizuje konto z początkowym depozytem i aktualizuje statyczne zmienne.
   - Destruktor wyświetla informacje o zamykanym koncie.

3. **Metody:**
   - `makeDeposit`: dodaje wpłatę do konta i aktualizuje statyczne zmienne.
   - `makeWithdrawal`: odejmuje wypłatę z konta, jeśli jest wystarczająca ilość środków, i aktualizuje statyczne zmienne.
   - `checkAmount`: zwraca aktualny stan konta.
   - `displayStatus`: wyświetla szczegóły konta.
   - `displayAccountsInfos`: wyświetla informacje o wszystkich kontach.
   - `_displayTimestamp`: wyświetla znacznik czasu.

### Wyjaśnienie implementacji:

1. **Statyczne zmienne:**
   - Przechowują globalne informacje o wszystkich kontach.

2. **Konstruktor i destruktor:**
   - Konstruktor inicjalizuje konto, przypisuje indeks i aktualizuje statystyki.
   - Destruktor wyświetla informacje o zamykanym koncie.

3. **Metody:**
   - `makeDeposit`: Dodaje wpłatę do konta i aktualizuje statystyki.
   - `makeWithdrawal`: Sprawdza, czy wypłata jest możliwa, i aktualizuje statystyki.
   - `displayStatus`: Wyświetla szczegóły konta.
   - `displayAccountsInfos`: Wyświetla globalne informacje o wszystkich kontach.
   - `_displayTimestamp`: Wyświetla znacznik czasu w formacie `[YYYYMMDD_HHMMSS]`.
*/
  
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Inicjalizacja statycznych zmiennych
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Prywatna metoda do wyświetlania znacznika czasu
void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year
              << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
              << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}

// Konstruktor
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destruktor
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Statyczne metody
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Metody instancji
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

