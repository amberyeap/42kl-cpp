#include "PmergeMe.hpp"

bool isNumber(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool isDuplicate(std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = i + 1; j < vec.size(); j++) {
			if (vec[i] == vec[j])
				return true;
		}
	}
	return false;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Insufficient numbers" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; i++) {
        if (!isNumber(argv[i])) {
            std::cerr << "Error: invalid input => " << argv[i] << std::endl;
            return 1;
        }

        int num = atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: only positive integers" << std::endl;
            return 1;
        }

        vec.push_back(num);
        deq.push_back(num);
    }

	if (isDuplicate(vec)) {
		std::cerr << "Error: contains duplicate" << std::endl;
		return 1;
	}

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

	// main sort
	PmergeMe merge;

	// std::clock() returns number of CPU clock ticks
	std::clock_t startVec = std::clock();
	merge.sort(vec);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	merge.sort(deq);
	std::clock_t endDeq = std::clock();

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	// CLOCKS_PER_SEC -> get seconds
	// multiply by 1000000 -> get microseconds
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << timeVec << "us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque : " << timeDeq << "us" << std::endl;

    return 0;
}