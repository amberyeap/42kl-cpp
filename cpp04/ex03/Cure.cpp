/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:07:21 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 18:07:21 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria::AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
	this->type = AMateria::type;
}

Cure::Cure(const Cure& other) : AMateria::AMateria("Cure") {
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}