/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:05:01 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 18:05:01 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria("Ice") {
	*this = other;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		//
	}
	return *this;
}

// returns a pointer to AMateria - a pointer to an inventory slot?
AMateria* Ice::clone() const {
	
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}