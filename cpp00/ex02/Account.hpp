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

		Account( int initial_deposit );
		~Account( void );

		void	makeDeposit( int deposit ); // adds money to account
		bool	makeWithdrawal( int withdrawal ); // removes money from account
		int		checkAmount( void ) const; // returns account balance
		void	displayStatus( void ) const; // displays account status

	private:

		static int	_nbAccounts;
		static int	_totalAmount; 
		static int	_totalNbDeposits;
		static int	_totalNbWithdrawals;

		static void	_displayTimestamp( void );

		int				_accountIndex; 
		int				_amount;
		int				_nbDeposits;
		int				_nbWithdrawals;

		Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
