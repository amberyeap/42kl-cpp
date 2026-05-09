/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:32:22 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/09 19:32:22 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void printInt(int const &n) {
	std::cout << n << std::endl;
}

void addTwo(int &i) {
	std::cout << i + 2 << std::endl;
}

int main() {
	int arr[] = {1, 2, 3};
	iter(arr, 3, printInt);
	iter(arr, 3, addTwo);
}