/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:09:01 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/14 12:09:01 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
	
	public:
		ClapTrap(); // default constructor
		ClapTrap(std::string name); // parameterised constructor
		ClapTrap(const ClapTrap& other); // copy constructor
		~ClapTrap(); // destructor

		ClapTrap& operator=(const ClapTrap& other); 

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// setters
		void setName(std::string name);
		void setHitPoints(unsigned int amount);
		void setEnergyPoints(unsigned int amount);
		void setAttackDamage(unsigned int amount);

		// getters
		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;

		void print() {
			std::cout << "\n[" << this->name << "'S STATUS]" << std::endl;
			std::cout << "HP: " << this->hitPoints << std::endl;
			std::cout << "Energy Points: " << this->energyPoints << std::endl;
			std::cout << "Attack Damage: " << this->attackDamage << std::endl;
		}
};

#endif