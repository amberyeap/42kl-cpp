/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:30:34 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/07 18:30:34 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void) {
	int x = std::rand() % 3;
	if (x == 0)
		return new A();
	else if (x == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	// cannot add and print e.what() when an exception is caught
	// -> seems to get corrupted and prints unnecessary messages

	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception& e) {}

	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception& e) {}
	
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception& e) {}

}

int main() {
	// needed to create a new seed so that the order is randomised
	// rand() doesn't actually generate random numbers, so without the seed,
	// the same sequence will always be used
	std::srand(std::time(NULL));

	for (int i = 1; i < 6; i++) {
		std::cout << "Round: " << i << std::endl;

		Base* test = generate();
		std::cout << "Pointer: ";
		identify(test);
		std::cout << "Reference: ";
		identify(*test);

		std::cout << std::endl;

		delete test;
	}

	return 0;
}