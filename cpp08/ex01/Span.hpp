/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:23:40 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/11 23:23:40 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		unsigned int _maxN;
		std::vector<int> _data;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(int n);

		template <typename Container>
		void addMultipleNums(const Container& cont);

		int shortestSpan();
		int longestSpan();

		class ExceedLimitException : public std::exception {
			public:
				const char* what() const throw() {
					return "Limit exceeded. Cannot add new number.";
				}
		};

		class InsufficientNumsException : public std::exception {
			public:
				const char* what() const throw() {
					return "Not enough numbers.";
				}
		};
};

template <typename Container>
void Span::addMultipleNums(const Container& cont) {
	if (_data.size() + cont.size() > _maxN)
		throw Span::ExceedLimit();
	_data.insert(_data.end(), cont.begin(), cont.end());
}

#endif