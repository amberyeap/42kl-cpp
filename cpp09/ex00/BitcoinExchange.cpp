/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 02:31:05 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/14 02:31:05 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	parseCsvFile();
	displayMap(_dataMap);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
	: _dataMap(other._dataMap) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->_dataMap = other._dataMap;
	return *this;
}

// parse through the csv file - store into a map

// parse the input text into a map

void BitcoinExchange::parseCsvFile() {
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(file, line); //get rid of the first line "data,exchange_rate"

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, value;

		if (std::getline(ss, date, ',') && std::getline(ss, value))
			_dataMap[date] = atof(value.c_str());
	}
}

void BitcoinExchange::displayMap(const std::map<std::string, float> map) {
	typedef typename std::map<std::string, float>::const_iterator iterator;

	for (iterator i = map.begin(); i != map.end(); i++)
		std::cout << i->first << ": " << i->second << std::endl;
}

// void BitcoinExchange::parseInput(const std::string& filename) {
// 	std::ifstream file(filename);

// 	std::string line;
// 	while (std::getline(file, line)) {
// 		std::stringstream ss(line);
// 		std::string 
// 	}
// }