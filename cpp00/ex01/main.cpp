/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:29:00 by ayeap             #+#    #+#             */
/*   Updated: 2025/02/25 18:29:00 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

int main() {
	PhoneBook phonebook;

	while (1)
	{
		std::string command;

		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "EXIT" || command == "exit") // or can also use command.std::string::compare("EXIT") == 0
			break;
		else if (command == "ADD" || command == "add")
			phonebook.AddContact();
		else if (command == "SEARCH" || command == "search")
			phonebook.SearchContact();
		else 
			std::cout << "Invalid command\n";
	}
	return 0;
}
