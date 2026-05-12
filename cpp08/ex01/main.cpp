/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:28:34 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/12 14:28:34 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int main() {

    {
        Span span(5);
        span.addNumber(6);
        span.addNumber(3);
        span.addNumber(17);
        span.addNumber(9);
        span.addNumber(11);
        std::cout << "shortest: " << span.shortestSpan() << std::endl;
        std::cout << "longest:  " << span.longestSpan() << std::endl;
    }

	std::cout << "\n[TESTING ADD MULTIPLE NUMS]" << std::endl;
    {
        Span span(10);
        std::vector<int> vector;
        vector.push_back(5);
        vector.push_back(1);
        vector.push_back(8);
        vector.push_back(3);
        span.addMultipleNums(vector);
        std::cout << "shortest: " << span.shortestSpan() << std::endl;
        std::cout << "longest:  " << span.longestSpan() << std::endl;
    }

    {
        Span span(10);
        std::list<int> list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        span.addMultipleNums(list);
        std::cout << "shortest: " << span.shortestSpan() << std::endl;
        std::cout << "longest:  " << span.longestSpan() << std::endl;
    }

	std::cout << "\n[TESTING 10000 NUMS]" << std::endl;
    {
        Span span(10000);
        std::vector<int> big;
        for (int i = 0; i < 10000; i++)
            big.push_back(i);
        span.addMultipleNums(big);
        std::cout << "shortest: " << span.shortestSpan() << std::endl;
        std::cout << "longest:  " << span.longestSpan() << std::endl;
    }

	std::cout << "\n[TESTING EXCEPTIONS]" << std::endl;
    {
        try {
            Span span(3);
            span.addNumber(1);
            span.addNumber(2);
            span.addNumber(3);
            span.addNumber(4);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        try {
            Span span(3);
            std::vector<int> vector;
            vector.push_back(1);
            vector.push_back(2);
            vector.push_back(3);
            vector.push_back(4);
            span.addMultipleNums(vector);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        try {
            Span span(5);
            span.addNumber(1);
            span.shortestSpan();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        try {
            Span span(5);
            span.longestSpan();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}