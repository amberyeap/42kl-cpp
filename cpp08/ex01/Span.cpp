/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 01:40:11 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/12 01:40:11 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxN(0), _data(NULL) {}

Span::Span(unsigned int N) : _maxN(N), _data(NULL) {}

Span::Span(const Span& other) : _maxN(other._maxN), _data(other._data) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_maxN = other._maxN;
		this->_data = other._data;
	}
	return *this;
}

void Span::addNumber(unsigned int n) {
	if (_data.size() >= _maxN)
		throw Span::ExceedLimit();
	_data.push_back(n);
}

unsigned int Span::shortestSpan() {
	if (_data.size() < 2)
		throw Span::InsufficientNums();
	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());
	return sorted[1] - sorted[0];
}

unsigned int Span::longestSpan() {
	if (_data.size() < 2)
		throw Span::InsufficientNums();
	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}