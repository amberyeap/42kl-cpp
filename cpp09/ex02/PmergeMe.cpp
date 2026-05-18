#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }

void PmergeMe::sort(std::vector<int>& arr) {
	fordJohnson(arr);
}

// void PmergeMe::sort(std::deque<int>& arr) {
// 	fordJohnson(arr);
// }

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

void PmergeMe::fordJohnson(std::vector<int>& arr) {
	if (arr.size() <= 1)
		return;

	// base case for recursion
	if (arr.size() == 2) {
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return;
	}

	bool hasLeftover = false;
	int leftover;
	if (arr.size() % 2 != 0) {
		leftover = arr.back();
		arr.pop_back();
		hasLeftover = true;
	}

	std::vector<int> main;
	std::vector<int> pend;

	for (size_t i = 0; i < arr.size(); i += 2) {
		if (arr[i] > arr[i + 1]) {
			main.push_back(arr[i]);
			pend.push_back(arr[i + 1]);
		}
		else {
			main.push_back(arr[i + 1]);
			pend.push_back(arr[i]);
		}
	}

	// recursively sort main until reaches base case of 2 nums
	fordJohnson(main);

	main.insert(main.begin(), pend[0]);

	std::vector<int> order = getJacobsthalOrder(pend.size());
	for (size_t i = 0; i < order.size(); i++)
		binaryInsert(main, pend[order[i]]);

	if (hasLeftover)
		binaryInsert(main, leftover);

	arr = main;
}