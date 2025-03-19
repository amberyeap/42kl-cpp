/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:01:22 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/18 18:01:22 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal parameterised constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::setType(std::string type) {
	this->type = type;
}

void Animal::makeSound() const {
	std::cout << "Some random animal sound" << std::endl;
}