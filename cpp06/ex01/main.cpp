/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 01:29:07 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/07 01:29:07 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data* original = new Data();
	original->firstName = "bob";
	original->lastName = "the builder";
	original->age = 42;

	std::cout << "Original data: " << original << std::endl;

	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Raw data: " << raw << std::endl;

	Data* backToOri = Serializer::deserialize(raw);
	std::cout << "Original data: " << backToOri << std::endl;
	std::cout << "Original data: " << backToOri->firstName << std::endl;
	std::cout << "Original data: " << backToOri->lastName << std::endl;
	std::cout << "Original data: " << backToOri->age << std::endl;

	return 0;
}