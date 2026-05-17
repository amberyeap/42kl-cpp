#include "PmergeMe.hpp"

bool isValidInput(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::digit(str[i]))
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Insufficient numbers" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; i++) {
        if (!isValidInput(argv[i])) {
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

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    return 0;
}