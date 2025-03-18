/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:04:23 by ayeap             #+#    #+#             */
/*   Updated: 2025/03/13 22:04:23 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float n1, const float n2) {
	std::cout << "Parameterised constructor called" << std::endl;
	this->x = n1;
	this->y = n2;
}

Point::Point(const Point& toCopy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Point::~Point() {}

Point& Point::operator=(Point const& toCopy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
		new ()
}

