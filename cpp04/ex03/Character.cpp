/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:07:45 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 18:07:45 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

ICharacter::~ICharacter() {
	std::cout << "ICharacter destructor called" << std::endl;
}

Character::Character() : name("default"), inventory_count(0) {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string name) : name(name) {
	std::cout << "Character param constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character& other) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < 4; i++) {
			this->inventory[i] = other.inventory[i];
		}
	}
	return *this;
}

// bool Character::operator==(const Character& other) const {
// 	if (this->name != other.name)
// 		return false;
// 	for (int i = 0; i < 4; i++) {
// 		if (this->inventory[i] != other.inventory[i])
// 			return false;
// 	}
// 	return true;
// }

std::string const& Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (inventory_count == 4) {
		std::cout << "Inventory full" << std::endl;
		return ;
	}

	this->inventory[inventory_count] = m;
	inventory_count++;
}

// incomplete - still need to figure out how to SAVE THE MATERIA ADDRESSES
void Character::unequip(int idx) {
	if (this->inventory[idx] == NULL || idx < 0 || idx > 3) {
		std::cout << "Nothing to unequip" << std::endl;
		return ;
	}
	int i = 0;
	while (floor[i] != NULL)
		i++;
	floor[i] = inventory[idx];
	inventory[idx] = NULL;
	inventory_count--;
	std::cout << "Item has dropped on the floor" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (this->inventory[idx] == NULL || idx < 0 || idx > 3) {
		std::cout << "...?" << std::endl;
		return ;
	}
	if (inventory[idx]->getType() == "ice") {
		Ice *ice = dynamic_cast<Ice *>(inventory[idx]);
		ice->use(target);
	}
	else if (inventory[idx]->getType() == "cure") {
		Cure *cure = dynamic_cast<Cure *>(inventory[idx]);
		cure->use(target);
	}
}