// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <ctime>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {

	public:

		typedef Account		t;

		static int	getNbAccounts( void ); // gets the number of accounts
		static int	getTotalAmount( void ); // returns sum of all account balances
		static int	getNbDeposits( void ); // returns total number of deposits
		static int	getNbWithdrawals( void ); // returns total number of withdrawals
		static void	displayAccountsInfos( void ); // displays all accounts info

		Account( int initial_deposit ); // constructor
		~Account( void ); // destructor

		void	makeDeposit( int deposit ); // adds money to account
		bool	makeWithdrawal( int withdrawal ); // removes money from account
		int		checkAmount( void ) const; // returns account balance
		void	displayStatus( void ) const; // displays account status

	private:

		static int	_nbAccounts; // holds data for the number of accounts
		static int	_totalAmount; // holds the total amount of all accounts
		static int	_totalNbDeposits; // the total deposits of all accounts
		static int	_totalNbWithdrawals; // total withdrawals of all accounts

		static void	_displayTimestamp( void );

		int				_accountIndex; // "account number"
		int				_amount; // the amount for the individual account
		int				_nbDeposits; // number of deposits for the individual account
		int				_nbWithdrawals; // number of withdrawals for the individual account

		Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
