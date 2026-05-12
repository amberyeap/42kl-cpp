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

Span::Span() : _maxN(0) {}

Span::Span(unsigned int N) : _maxN(N) {}

Span::Span(const Span& other) : _maxN(other._maxN), _data(other._data) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_maxN = other._maxN;
		this->_data = other._data;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_data.size() >= _maxN)
		throw Span::ExceedLimitException();
	_data.push_back(n);
}

int Span::shortestSpan() {
	if (_data.size() < 2)
		throw Span::InsufficientNumsException();
	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	int min = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < sorted.size() - 1; i++) {
		if (sorted[i + 1] - sorted[i] < min)
			min = sorted[i + 1] - sorted[i];
	}
	return min;
}

int Span::longestSpan() {
	if (_data.size() < 2)
		throw Span::InsufficientNumsException();
	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}