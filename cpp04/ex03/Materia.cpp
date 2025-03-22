/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:07:32 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 18:07:32 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria() {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type) {

}

std::string const& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
}