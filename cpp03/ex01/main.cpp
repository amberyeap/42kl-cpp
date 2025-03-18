/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:56:06 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/14 12:56:06 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap bob("bob");
	ClapTrap bub("bub");
	ScavTrap bib("bib");
	ScavTrap bab("bab");
	ScavTrap def; // to call the default constructor

	bob.attack("bub");
	bub.setAttackDamage(2);
	bob.takeDamage(bub.getAttackDamage());
	bob.beRepaired(3);

	bib.takeDamage(bub.getAttackDamage());
	bib.attack("bab");
	bib.beRepaired(5);
	bib.attack("bob");
	
	bab.guardGate();
	bab.attack("bob");
	bab.beRepaired(3);

	bob.print();
	bub.print();
	bib.print();
	bab.print();
	def.print();
}