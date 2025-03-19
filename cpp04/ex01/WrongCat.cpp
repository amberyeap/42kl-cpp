/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:43:49 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 14:43:49 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default created" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	this->type = type;
}

// WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.type) {
// 	*this = other;
// }

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "meow?" << std::endl;
}