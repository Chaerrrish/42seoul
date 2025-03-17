#include "PmergeMe.hpp"
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& PmergeMe) {
    if (this != &PmergeMe) {
        this->vec = PmergeMe.vec;
        this->deq = PmergeMe.deq;
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe& PmergeMe) {
    if (this != &PmergeMe) {
        this->vec = PmergeMe.vec;
        this->deq = PmergeMe.deq;
    }
    return *this;
}

PmergeMe::PmergeMe(char **argv) {
    for (int i = 1; argv[i]; i++) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            throw std::invalid_argument("Error: Only positive integers are allowed.");
        }
        vec.push_back(num);
        deq.push_back(num);
    }
}

void PmergeMe::execute() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    double vecTime = sortAndMeasure(vec);
    double deqTime = sortAndMeasure(deq);

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque: " << deqTime << " us" << std::endl;
}
