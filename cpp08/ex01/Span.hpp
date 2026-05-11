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

		void addNumber(unsigned int n);
		void addMultipleNums(unsigned int arr[]);

		unsigned int shortestSpan();
		unsigned int longestSpan();

		class ExceedLimit : public std::exception {
			public:
				const char* what() const throw() {
					return "Limit exceeded. Cannot add new number.";
				}
		}
}

#endif