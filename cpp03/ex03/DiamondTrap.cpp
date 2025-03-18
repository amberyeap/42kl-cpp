/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:22:09 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 16:22:09 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
	this->name = ClapTrap::getName();
	this->hitPoints = FragTrap::getHitPoints();
	this->energyPoints = ScavTrap::getEnergyPoints();
	this->attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	*this = other;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "\nDiamondTrap " << this->name << " has been destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		this->name = other.getName();
		this->hitPoints = other.getHitPoints();
		this->energyPoints = other.getEnergyPoints();
		this->attackDamage = other.getAttackDamage();
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "\n[IDENTITY CRISIS]" << std::endl;
	std::cout << this->name << " says ";
	std::cout << "\"Is my name " << this->name << " or is it " << ClapTrap::name << "?\"" << std::endl;
}