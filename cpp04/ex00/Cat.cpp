/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:15:24 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 18:15:24 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal::Animal("Cat") {
	this->type = Animal::getType();
	std::cout << "Default cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "purrrrrrrrrrrrr" << std::endl;
}