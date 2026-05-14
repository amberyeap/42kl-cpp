/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 02:07:20 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/14 02:07:20 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float> _dataMap;

		
		public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& other);

		void parseCsvFile();
		void displayMap(const std::map<std::string, float>map);
		void parseInput(const std::string& file);
		float getRate(const std::string& date);
};

#endif