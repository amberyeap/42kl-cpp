/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:56:16 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/03 19:56:16 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N;
	std::string name;

	std::cout << "Enter a number: ";
	std::cin >> N;

	std::cout << "Enter a name: ";
	std::cin >> name;

	Zombie* horde = zombieHorde(N, name);
	delete[] horde;

	return 0;
}