/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:55:25 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/15 13:55:25 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		this->_stack = other._stack;
	return *this;
}

int isOperator(const char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

int isNumber(const char c) {
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int runOperation(int num1, int num2, char op) {
	switch (op) {
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			if (num2 == 0)
				throw std::runtime_error("Error: cannot divide by zero");
			return num1 / num2;
	}
	throw std::runtime_error("Error: unknown operator");
}

void RPN::mathIt(const std::string& str) {
	

	for (size_t i = 0; i < str.length(); i++) {
		if (isOperator(str[i])) {
			if (_stack.size() < 2) {
				std::cerr << "Error: insufficient numbers" << std::endl;
				return;
			}
			int num2 = _stack.top();
			_stack.pop();
			int num1 = _stack.top();
			_stack.pop();

			_stack.push(runOperation(num1, num2, str[i]));
		}
		else if (isNumber(str[i])) {
			_stack.push(str[i] - '0');
		}
		else if (str[i] == ' ')
			continue;
		else {
			std::cerr << "Error: invalid token" << std::endl;
			return;
		}
	}

	if (_stack.size() != 1) {
		std::cerr << "Error: invalid math" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}