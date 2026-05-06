/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:42:14 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/05 16:42:14 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {
	std::cout << "[TESTING CHAR]" << std::endl;
	ScalarConverter::convert("a");
	ScalarConverter::convert("Z");
	ScalarConverter::convert(" "); // non printable

	std::cout << std::endl;

	std::cout << "[TESTING INT]" << std::endl;
	ScalarConverter::convert("0");
	ScalarConverter::convert("42");
	ScalarConverter::convert("-42");
	ScalarConverter::convert("2026");
	ScalarConverter::convert("-2147483647"); // INT MIN
	ScalarConverter::convert("2147483647"); //INT MAX
	ScalarConverter::convert("2147483648"); // overflow

	std::cout << std::endl; 

	std::cout << "[TESTING FLOAT]" << std::endl;
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("42.0f");
	ScalarConverter::convert("-42.5f");
	ScalarConverter::convert("42.9999f");

	std::cout << std::endl;

	std::cout << "[TESTING DOUBLE]" << std::endl;
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("42.0");
	ScalarConverter::convert("-42.5");

	std::cout << std::endl;

	std::cout << "[TESTING PSUEDO LITERAL]" << std::endl;
	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("-inff");

	return 0;
}