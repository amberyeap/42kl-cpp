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
	if (this->energyPoints != 0 && this->hitPoints != 0) {
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " has " << this->energyPoints << " energy points remaining" << std::endl;
	}
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints != 0) {
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage!" << std::endl;
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hit points remaining" << std::endl;
	}
	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints != 0 && this->hitPoints != 0) {
		std::cout << "ClapTrap " << this->name << " has repaired " << amount << " hit points!" << std::endl;
		this->energyPoints--;
		for (unsigned int i = 0; i < amount; i++) {
			this->hitPoints++;
			if (this->hitPoints == 10)
				break;
		}
		std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hit points remaining" << std::endl;
		std::cout << "ClapTrap " << this->name << " has " << this->energyPoints << " energy points remaining" << std::endl;
	}
	return ;
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

int ClapTrap::getHitPoints() {
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints() {
	return this->energyPoints;
}

int ClapTrap::getAttackDamage() {
	return this->attackDamage;
}