/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:00:01 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/13 22:00:01 by ayeap            ###   ########.fr       */
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
	std::cout << "Integer constructor called" << std::endl;
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

bool Fixed::operator > (Fixed const& num) const {
	return this->getRawBits() > num.getRawBits();
}

bool Fixed::operator < (Fixed const& num) const {
	return this->getRawBits() < num.getRawBits();
}

bool Fixed::operator >= (Fixed const& num) const {
	return this->getRawBits() >= num.getRawBits();
}

bool Fixed::operator <= (Fixed const& num) const {
	return this->getRawBits() <= num.getRawBits();
}

bool Fixed::operator == (Fixed const& num) const {
	return this->getRawBits() == num.getRawBits();
}

bool Fixed::operator != (Fixed const& num) const {
	return this->getRawBits() != num.getRawBits();
}

Fixed Fixed::operator + (Fixed const& num) const {
	return Fixed(this->toFloat() + num.toFloat());
}

Fixed Fixed::operator - (Fixed const& num) const {
	return Fixed(this->toFloat() - num.toFloat());
}

Fixed Fixed::operator * (Fixed const& num) const {
	return Fixed(this->toFloat() * num.toFloat());
}

Fixed Fixed::operator / (Fixed const& num) const {
	return Fixed(this->toFloat() / num.toFloat());
}

Fixed& Fixed::operator ++ () {
	++fixedPoint;
	return *this;
}

Fixed Fixed::operator ++ (int) {
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed& Fixed::operator -- () {
	--fixedPoint;
	return *this;
}

Fixed Fixed::operator -- (int) {
	Fixed temp(*this);
	operator--();
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed const& Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

Fixed const& Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return a;
	return b;
}

std::ostream& operator << (std::ostream& op, Fixed const& fixed) {
	op << fixed.toFloat();
	return op;
}