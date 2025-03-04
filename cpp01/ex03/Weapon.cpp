/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:11:57 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/03 21:11:57 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type) {
}

Weapon::~Weapon() {
}

const std::string& Weapon::getType() const {
	return type;
}

void Weapon::setType(const std::string &type) {
	this->type = type;
}
