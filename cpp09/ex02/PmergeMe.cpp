#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }

// use the jacobsthal algo to determine the order of numbers inserted
// use binaryInsert algo to insert in the proper location

// insert the chosen one into the right spot
void PmergeMe::binaryInsert(std::vector<int>& arr, int val) {
	int low = 0;
	int high = arr.size();

	while (low < high) {
		int mid = (low + high) / 2;
		if (arr[mid] < val)
			low = mid + 1;
		else
			high = mid;
	}
	arr.insert(arr.begin() + low, val);
}

