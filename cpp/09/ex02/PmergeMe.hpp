#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;

    template <typename Container>
    void mergeInsertSort(Container &arr);

    template <typename Container>
    double sortAndMeasure(Container &arr);

    std::vector<int> generateJacobsthalSequence(int n) {
        std::vector<int> seq;
        seq.push_back(0);
        seq.push_back(1);
        while (seq.back() < n) {
            seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
        }
        return seq;
    }

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& PmergeMe);
    PmergeMe& operator=(const PmergeMe& PmergeMe);
    PmergeMe(char **argv);
    void execute();
};

template <typename Container>
void PmergeMe::mergeInsertSort(Container &arr) {
    if (arr.size() <= 1) return;

    typename Container::iterator mid = arr.begin() + arr.size() / 2;
    Container left(arr.begin(), mid);
    Container right(mid, arr.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    std::vector<int> jacobsthal = generateJacobsthalSequence(right.size());
    std::vector<bool> used(right.size(), false);

    for (size_t i = 0; i < jacobsthal.size(); i++) {
        if (jacobsthal[i] >= right.size()) break;
        if (used[jacobsthal[i]]) continue;
        typename Container::iterator it = right.begin() + jacobsthal[i];
        typename Container::iterator pos = std::lower_bound(left.begin(), left.end(), *it);
        left.insert(pos, *it);
        used[jacobsthal[i]] = true;
    }

    for (size_t i = 0; i < right.size(); i++) {
        if (!used[i]) {
            typename Container::iterator it = right.begin() + i;
            typename Container::iterator pos = std::lower_bound(left.begin(), left.end(), *it);
            left.insert(pos, *it);
        }
    }

    arr.clear();
    arr.insert(arr.end(), left.begin(), left.end());
}


template <typename Container>
double PmergeMe::sortAndMeasure(Container &arr) {
    std::clock_t start = std::clock();
    mergeInsertSort(arr);
    std::clock_t end = std::clock();
    return 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

#endif
