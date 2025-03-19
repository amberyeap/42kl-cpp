/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:15:30 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 18:15:30 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "[VIRTUAL KEYWORD INCLUDED]" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete i;
	delete j;
	
	std::cout << "\n[VIRTUAL KEYWORD EXCLUDED]" << std::endl;

	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();
	
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;

	k->makeSound();
	l->makeSound();

	delete k;
	delete l;

	return 0;
}