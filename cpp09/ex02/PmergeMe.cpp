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

std::vector<int> PmergeMe::getJacobsthalOrder(size_t size) {
	std::vector<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	while (jacob.back() < (int)size)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	std::vector<int> order;
	std::vector<bool> added(size, false);

	for (size_t i = 0; i < jacob.size(); i++) {
		int end = std::min((int)size - 1, jacob[i] - 1);
		int start;

		if (i == 0)
			start = 1;
		else
			start = jacob[i - 1];

		for (int j = end; j >= start; j--) {
			if (j < (int)size && !added[j]) {
				order.push_back(j);
				added[j] = true;
			}
		}
	}

	for (size_t i = 1; i < size; i++) {
		if (!added[i])
			order.push_back(i);
	}

	return order;
}