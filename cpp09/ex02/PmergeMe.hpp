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

        void sort(std::vector<int>& arr);
        void sort(std::deque<int>& arr);
};

#endif