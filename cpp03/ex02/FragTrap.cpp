/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:40:20 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 15:40:20 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
}

FragTrap::~FragTrap() {
	std::cout << "\nFragTrap " << this->name << " was destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "[HIGH FIVE?]" << std::endl;
	std::cout << "FragTrap " << this->name << " says \"High five, guys! Please? :3\" ... in the middle of a fight..." << std::endl;
}