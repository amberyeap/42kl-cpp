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

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria("Cure") {
	*this = other;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		// what to copy over?
	}
	return *this;
}

AMateria* Cure::clone() const {

}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}