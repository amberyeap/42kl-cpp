/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:05:53 by ayeap             #+#    #+#             */
/*   Updated: 2025/02/25 17:05:53 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

// Constructor
Contact::Contact() {
}

// Destructor
Contact::~Contact() {
}

// setters
void Contact::setFirstName(std::string FirstName) {
	this->FirstName = FirstName;
}

void Contact::setLastName(std::string LastName) {
	this->LastName = LastName;
}

void Contact::setNickname(std::string Nickname) {
	this->Nickname = Nickname;
}

void Contact::setPhoneNumber(std::string PhoneNumber) {
	this->PhoneNumber = PhoneNumber;
}

void Contact::setDarkestSecret(std::string DarkestSecret) {
	this->DarkestSecret = DarkestSecret;
}

// getters
std::string Contact::getFirstName() {
	return FirstName;
}

std::string Contact::getLastName() {
	return LastName;
}

std::string Contact::getNickname() {
	return Nickname;
}

std::string Contact::getPhoneNumber() {
	return PhoneNumber;
}

std::string Contact::getDarkestSecret() {
	return DarkestSecret;
}