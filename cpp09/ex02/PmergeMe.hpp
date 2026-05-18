#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cctype>
#include <ctime>

class PmergeMe {
	private:
		void binaryInsert(std::vector<int>& arr, int val);
		void fordJohnson(std::vector<int>& arr);

		void binaryInsert(std::deque<int>& arr, int val);
		void fordJohnson(std::deque<int>& arr);

		std::vector<int> getJacobsthalOrder(size_t size);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& other);

        void sort(std::vector<int>& arr);
        void sort(std::deque<int>& arr);
};

#endif