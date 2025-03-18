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

int main() {
	ClapTrap bob("bob");
	ClapTrap bub("bub");

	bob.attack("bub");
	bub.setAttackDamage(2);
	bob.takeDamage(bub.getAttackDamage());
	bob.beRepaired(3);
}