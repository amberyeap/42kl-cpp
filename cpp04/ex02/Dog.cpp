/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:15:28 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 18:15:28 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal::Animal("Dog") {
	this->type = Animal::getType();
	this->dogBrain = new Brain();
	std::cout << "Default dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

Dog::~Dog() {
	delete dogBrain;
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof" << std::endl;
}