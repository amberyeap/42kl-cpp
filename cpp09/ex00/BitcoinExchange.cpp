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
	// displayMap(_dataMap);
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

int isValidDate(const std::string& date) {
	// YYYY-MM-DD

	if (date.length() != 10)
		return 0;
	if (date[4] != '-' || date[7] != '-')
		return 0;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return 0;
	}

	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return 0;
	if (day < 1 || day > 31)
		return 0;
	return 1;
}

float BitcoinExchange::getRate(const std::string& date) {
	std::map<std::string, float>::iterator it = _dataMap.lower_bound(date);

	if (it != _dataMap.end() && it->first == date)
		return it->second;

	if (it == _dataMap.begin()) {
		std::cerr << "Error: no rate found for " << date << std::endl;
		return -1;
	}

	it--;
	return it->second;
}

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

void BitcoinExchange::parseInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string line;
	std::getline(file, line); // removes the "data | value" line

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, value;

		size_t pipe = line.find('|');
		if (pipe == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		date = line.substr(0, pipe - 1);
		value = line.substr(pipe + 1);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value.empty()) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		float newValue = atof(value.c_str());
		if (newValue < 0) {
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		}

		if (newValue > 1000) {
			std::cerr << "Error: too large a number" << std::endl;
			continue;
		}

		float rate = getRate(date);
		if (rate < 0)
			continue;
		std::cout << date << " => " << newValue << " = " << (rate * newValue) << std::endl;
	}
}