/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:28:17 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/25 13:28:17 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

IMateriaSource::~IMateriaSource() {
	std::cout << "IMateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource() : storage_count(0) {
	std::cout << "MateriaSource default constructor called" << std::endl;
}

// MateriaSource::MateriaSource(std::string type) {
// 	std::cout << "MateriaSource param constructor called" << std::endl;
// }

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			this->materiaStorage[i] = other.materiaStorage[i];
		}
	}
	return *this;
}

void MateriaSource::getMemory() const {
	std::cout << "MateriaSource memory: " << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "MateriaSource " << i << ": " << this->materiaStorage[i]->getType() << std::endl;
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (storage_count == 4) {
		std::cout << "MateriaSource full!" << std::endl;
		return ;
	}
	this->materiaStorage[storage_count] = m;
	this->storage_count++;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (materiaStorage[i]->getType() == type) {
			return this->materiaStorage[i];
		}
	}
	std::cout << "Materia " << type << " does not exist in memory" << std::endl;
	return NULL;
}