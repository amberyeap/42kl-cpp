/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:05:50 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/11 19:05:50 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> nums(arr, arr + 5);

	try {
        std::vector<int>::iterator it = easyfind(nums, 2);
        std::cout << "Found: " << *it << std::endl;
        easyfind(nums, 99);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
	}
}