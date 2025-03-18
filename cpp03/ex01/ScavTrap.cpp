/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:23:09 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/16 15:23:09 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// default constructor
ScavTrap::ScavTrap() : ClapTrap() {
	setName("default");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << " created" << std::endl;
}

// parameterised constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << " created" << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.getName()) {
	*this = other;
}

// destructor
ScavTrap::~ScavTrap() {
	std::cout << "\nScavTrap " << this->getName() << " destroyed" << std::endl;
}

// copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "\n[ATTACKING]" << std::endl;
	std::cout << "ScavTrap " << this->getName() << " attacked " << target << " causing " << this->getAttackDamage() << " attack damage" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "\n[GATEKEEPING]" << std::endl;
	std::cout << "ScavTrap is in Gatekeeper mode" << std::endl;
}