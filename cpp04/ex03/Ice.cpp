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

Ice::Ice() : AMateria::AMateria("Ice") {
	std::cout << "Ice default constructor called" << std::endl;
	this->type = AMateria::type;
}

Ice::Ice(const Ice& other) : AMateria::AMateria("Ice") {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// returns a pointer to AMateria - a pointer to an inventory slot?
AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}