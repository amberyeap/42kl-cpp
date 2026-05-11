/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 02:01:06 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/11 02:01:06 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {

	//testing with ints
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i + 2;

	//to prove deep copy - b must not affect a
    Array<int> b(a);
    b[0] = 42;
    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    Array<int> c;
    c = a;
    c[1] = 2026;
    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl;

    try {
        std::cout << a[10] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	std::cout << std::endl;

	// testing with string
    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world!";
    s[2] = "the earth says hello";
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
    std::cout << std::endl;

	try {
        std::cout << s[10] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}