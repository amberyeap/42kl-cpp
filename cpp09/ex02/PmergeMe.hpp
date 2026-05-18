#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cctype>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& other);

		void binaryInsert(std::vector<int>& arr, int val);
		std::vector<int> getJacobsthalOrder(size_t size);
		void fordJohnson(std::vector<int>& arr);
};

#endif