/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:46:17 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/05 16:46:17 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum eType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL
};

static eType detectType(const std::string& str) {
	if (str == "nanf" || str == "+inff" || str == "-inff" ||
		str == "nan" || str == "+inf" || str == "-inf") {
			return SPECIAL;
		}
	else if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR;
	else if (str.find('.') != std::string::npos && str[str.length() - 1] == 'f')
		return FLOAT;
	else if (str.find('.') != std::string::npos)
		return DOUBLE;
	else
		return INT;
}

void printConvert(double s) {
	// prints char
	std::cout << "char: ";
	if ((s > 31 && s < 127) && std::isprint(static_cast<int>(s)))
		std::cout << "'" << static_cast<char>(s) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	// prints int
	std::cout << "int: ";
	if (s < INT_MIN || s > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(s) << std::endl;

	// prints float
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << s;
	std::cout << "f" << std::endl;

	// prints double
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << s << std::endl;

	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& str) {

	//detect the type
	eType type = detectType(str);

	std::cout << "Original String: " << str << std::endl;

	if (type == SPECIAL) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "nan" || str == "nanf") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (str == "+inf" || str == "+inff") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (str == "-inf" || str == "-inff") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		std::cout << std::endl;

		return;
	}

	double s;
	if (type == CHAR)
		s = static_cast<double>(str[0]);
	else if (type == INT)
		s = static_cast<double>(std::atoi(str.c_str()));
	else if (type == FLOAT)
		s = static_cast<double>(std::atof(str.c_str()));
	else
		s = std::atof(str.c_str());

	printConvert(s);
}