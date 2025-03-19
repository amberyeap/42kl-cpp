/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:13:24 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/19 15:13:24 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <memory>

Brain::Brain() {
	std::cout << "Default brain created" << std::endl;
	// std::cout << "address of " << this << std::endl;
}

// Brain::Brain(std::string idea) {
// 	this->ideas[] = idea;
// }

Brain::Brain(const Brain& other) {
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}