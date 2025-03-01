/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:11:40 by ayeap             #+#    #+#             */
/*   Updated: 2025/02/26 17:11:40 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;	

Account::Account(int initial_deposit) {
}

Account::~Account(void) {
}

int Account::getNbAccounts(void) {
	
}

int Account::getTotalAmount(void) {

}

int Account::getNbDeposits(void) {

}

int Account::getNbWithdrawals(void) {

}

void Account::displayAccountsInfos(void) {

}

void Account::makeDeposit(int deposit) {

}

bool Account::makeWithdrawal(int withdrawal) {

}

int Account::checkAmount(void) const {

}

void Account::displayStatus(void) const {

}

void Account::_displayTimestamp(void) {
	time_t now = time(NULL);
	struct tm time = *localtime(&now);

	char print_time[100];

	strftime(print_time, 100, "[%Y%m%d_%H%M%S] ", &time);

	std::cout << print_time;
}
