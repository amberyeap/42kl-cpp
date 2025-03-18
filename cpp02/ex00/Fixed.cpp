/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:50:07 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/06 13:50:07 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& toCopy) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPoint = toCopy.fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& toCopy) {
	std::cout << "Copy assignment operator called" << std::endl;
	fixedPoint = toCopy.fixedPoint;
	return *this;
} 

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	fixedPoint = raw;
}