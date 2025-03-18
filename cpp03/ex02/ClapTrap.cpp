/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:15:01 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/14 12:15:01 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
}

// parameterised constructor
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " was created" << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
}

// destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " was destroyed" << std::endl;
}

// copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "\n[ATTACKING]" << std::endl;
	if (this->energyPoints != 0 && this->hitPoints != 0) {
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " has " << this->energyPoints << " energy points remaining" << std::endl;
	}
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "\n[TAKING DAMAGE]" << std::endl;
	if (this->hitPoints != 0) {
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage!" << std::endl;
		if (this->hitPoints != 0) {
			for (unsigned int i = 0; i < amount; i++) {
				this->hitPoints--;
				if (this->hitPoints == 0)
					break;
			}
			std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " HP remaining" << std::endl;
		}
	}
	else
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "\n[REPAIRING]" << std::endl;
	if (this->energyPoints != 0 && this->hitPoints != 0) {
		std::cout << "ClapTrap " << this->name << " has repaired " << amount << " HP!" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
		// for (unsigned int i = 0; i < amount; i++) {
		// 	this->hitPoints++;
		// 	if (this->hitPoints == 100 || this->hitPoints == 10)
		// 		break;
		// }
		std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " HP remaining" << std::endl;
		std::cout << "ClapTrap " << this->name << " has " << this->energyPoints << " energy points remaining\n" << std::endl;
	}
	return ;
}

void ClapTrap::setName(std::string name) {
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int amount) {
	this->hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
	this->energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
	this->attackDamage = amount;
}

std::string ClapTrap::getName() const {
	return this->name;
}

unsigned int ClapTrap::getHitPoints() const {
	return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}