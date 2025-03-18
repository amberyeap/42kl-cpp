/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:58:30 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/06 14:58:30 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& toCopy) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPoint = toCopy.fixedPoint;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	fixedPoint = num << fractBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf(num * (1 << fractBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& toCopy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
		fixedPoint = toCopy.fixedPoint;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	fixedPoint = raw;
}

float Fixed::toFloat(void) const {
	return (float)fixedPoint / (1 << fractBits);
}

int Fixed::toInt(void) const {
	return fixedPoint >> fractBits;
}

std::ostream& operator<<(std::ostream& op, Fixed const& fixed) {
	op << fixed.toFloat();
	return op;
}