/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:27:33 by ayeap             #+#    #+#             */
/*   Updated: 2025/02/25 18:27:33 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

PhoneBook::PhoneBook() : ContactCount(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::AddContact() {
	std::string first;
	std::string last;
	std::string nick;
	std::string phone;
	std::string secret;
	
	if (ContactCount == 8)
		ContactCount = 0;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first);
	contacts[ContactCount].setFirstName(first);

	std::cout << "Enter last name: ";
	std::getline(std::cin, last);
	contacts[ContactCount].setLastName(last);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nick);
	contacts[ContactCount].setNickname(nick);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone);
	contacts[ContactCount].setPhoneNumber(phone);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, secret);
	contacts[ContactCount].setDarkestSecret(secret);

	ContactCount++;
}

std::string PhoneBook::TrimString(std::string str) {
	if (str.length() < 10)
		return str;
	return str.substr(0, 9) + ".";
}

void PhoneBook::SearchContact() {
	if (ContactCount == 0) {
		std::cout << "No contacts available\n";
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickanme" << "|" << std::endl;

	for (int i = 0; i < ContactCount; i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << TrimString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << TrimString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << TrimString(contacts[i].getNickname()) << "|" << std::endl;
	}

	DisplayContact();
}

void PhoneBook::DisplayContact() {
	std::string index;

	std::cout << "Enter index: ";
	std::cin >> index;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (index.length() == 1 && index[0] >= '1' && index[0] <= '8') {
		int i = index[0] - '1';

		if (i < ContactCount) {
		std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[i].getDarkestSecret() << std::endl;
		}
		else
			std::cout << "Invalid index\n";
	}
	else
		std::cout << "Invalid index\n";
}