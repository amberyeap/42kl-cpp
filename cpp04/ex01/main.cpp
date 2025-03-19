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
	const Animal* anotherCat = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const Cat* iPtr = dynamic_cast<const Cat*>(i);
	const Cat* anotherCatPtr = dynamic_cast<const Cat*>(anotherCat);

	std::cout << "address of i's brain: " << iPtr->getBrain() << std::endl;
	std::cout << "address of anotherCat's brain: " << anotherCatPtr->getBrain() << std::endl;

	// std::cout << "address of i: " << &i << std::endl;
	// std::cout << "address of j: " << &j << std::endl;
	
	delete meta;
	delete i;
	delete j;
	delete anotherCat;
	
	std::cout << "\n[VIRTUAL KEYWORD EXCLUDED]" << std::endl;

	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();
	
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;

	k->makeSound();
	l->makeSound();

	delete k;
	delete l;

	std::cout << "\n[TESTING SHALLOW COPY]" << std::endl;

	const Animal* cat = new Cat();
	const Animal* dog = cat;

	const Cat* catPtr = dynamic_cast<const Cat*>(cat);
	const Cat* dogPtr = dynamic_cast<const Cat*>(dog);

	std::cout << "address of cat's brain: " << catPtr->getBrain() << std::endl;
	std::cout << "address of dog's brain: " << dogPtr->getBrain() << std::endl;

	delete cat;

	return 0;
}