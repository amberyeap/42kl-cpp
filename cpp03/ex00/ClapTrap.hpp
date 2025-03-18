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
	private:
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
		void setHitPoints(unsigned int amount);
		void setEnergyPoints(unsigned int amount);
		void setAttackDamage(unsigned int amount);

		// getters
		int getHitPoints();
		int getEnergyPoints();
		int getAttackDamage();
};

#endif