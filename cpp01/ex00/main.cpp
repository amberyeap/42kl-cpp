/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:29:37 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/03 18:29:37 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	std::string name;
	
	std::cout << "Enter a name: ";
	std::cin >> name;

	std::cout << "Calling a heap zombie" << std::endl;
	Zombie* zombie = newZombie(name);
	zombie->announce();
	delete zombie;

	std::cout << "Calling a stack zombie" << std::endl;
	randomChump(name);
	return 0;
}