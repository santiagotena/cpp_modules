/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:31 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:32 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Private //
PmergeMe::PmergeMe(PmergeMe &src) {*this = src;}

PmergeMe    &PmergeMe::operator=(PmergeMe &src) {
    _arraySize = src._arraySize;
    if (_arraySize > 0) {
        delete[] _arrayNumbers;
        _arrayNumbers = new int[_arraySize];
        for (int i = 0; i < _arraySize; i++)
            _arrayNumbers[i] = src._arrayNumbers[i];
    }
    if (!_setNumbers.empty()) {
        _setNumbers.clear();
        std::set<int>::const_iterator setIt;
        for (setIt = src._setNumbers.begin(); setIt != src._setNumbers.end(); ++setIt)
            _setNumbers.insert(*setIt);
    }
    if (!_listNumbers.empty()) {
        _listNumbers.clear();
        std::list<int>::const_iterator listIt;
        for (listIt = src._listNumbers.begin(); listIt != src._listNumbers.end(); ++listIt)
            _listNumbers.push_back(*listIt);
    }
    if (!_dequeNumbers.empty()) {
        std::deque<int>::const_iterator dequeIt;
        for (dequeIt = src._dequeNumbers.begin(); dequeIt != src._dequeNumbers.end(); ++dequeIt)
            _dequeNumbers.push_back(*dequeIt);
    }
    return (*this);
}

template <typename Container, typename Iterator>
void    PmergeMe::_mergeInsertSort(Container& cont, Iterator low, Iterator high) {
    if (low != high) {
        if (std::distance(low, high) <= 4) {
            // Use insertion sort for small subcontainers
            for (Iterator i = low; i != high; ++i) {
                typename Container::value_type key = *i;
                Iterator j = i;
                while (j != low && *std::prev(j) > key) {
                    *j = *std::prev(j);
                    --j;
                }
                *j = key;
            }
        } else {
            // Divide the container into two halves
            Iterator mid = low;
            std::advance(mid, std::distance(low, high) / 2);
            // Recursively sort the two halves
            _mergeInsertSort(cont, low, mid);
            _mergeInsertSort(cont, mid, high);
            // Merge the sorted halves
            _merge(cont, low, mid, high);
        }
    }
}

template <typename Container, typename Iterator>
void    PmergeMe::_merge(Container& cont, Iterator low, Iterator mid, Iterator high) {
    Container temp;
    Iterator i = low;
    Iterator j = mid;
    // Merge the two sorted subcontainers into temp
    while (i != mid && j != high) {
        if (*i <= *j) {
            temp.push_back(*i);
            ++i;
        } else {
            temp.push_back(*j);
            ++j;
        }
    }
    // Copy the remaining elements from the first subcontainer, if any
    while (i != mid) {
        temp.push_back(*i);
        ++i;
    }
    // Copy the remaining elements from the second subcontainer, if any
    while (j != high) {
        temp.push_back(*j);
        ++j;
    }
    // Copy the merged elements back to the original container
    Iterator it = low;
    for (typename Container::iterator tempIt = temp.begin(); tempIt != temp.end(); ++tempIt, ++it)
        *it = *tempIt;
}

void    PmergeMe::_exitProgram() {
    delete[] _arrayNumbers;
    exit(-1);
}

int    PmergeMe::_assignNumber(std::string element) {
    int number;

    std::istringstream iss(element);
    if (!(iss >> number)) {
        std::cout << ERR_ONLY_POSITIVE << std::endl;
        _exitProgram();
    }
    return (number);
}

bool    PmergeMe::_isNumberPositive(int number) {
    if (number <= 0) {
        std::cout << ERR_ONLY_POSITIVE << std::endl;
        return (false);
    }
    return (true);
}

bool    PmergeMe::_areDuplicatesPresent() {
    for (int i = 0; i < (_arraySize - 1); i++) {
        for (int j = (i + 1); j < (_arraySize); j++) {
            if (_arrayNumbers[i] == _arrayNumbers[j]) {
                std::cout << ERR_NO_DUPLICATES << std::endl;
                return (true);
            }
        }
    }
    return (false);
}

void    PmergeMe::_displayStartingArray() {
    std::cout << "Before:\t";
    for (int i = 0; i < (_arraySize); i++) {
        std::cout << _arrayNumbers[i] << " ";
    }
    std::cout << std::endl;
}

double  PmergeMe::_timeToSort(std::string container) {
    clock_t	timeStart;
    clock_t timeEnd;

    if (container == "set") {
        timeStart = clock();
        for (int i = 0; i < _arraySize; i++)
            _setNumbers.insert(_arrayNumbers[i]);
        timeEnd = clock();
        return((double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3);
    }
    else if (container == "list") {
        for (int i = 0; i < _arraySize; i++)
            _listNumbers.push_back(_arrayNumbers[i]);
        timeStart = clock();
        _mergeInsertSort(_listNumbers, _listNumbers.begin(), _listNumbers.end());
        timeEnd = clock();
        return((double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3);
    }
    else if (container == "deque") {
        for (int i = 0; i < _arraySize; i++)
            _dequeNumbers.push_back(_arrayNumbers[i]);
        timeStart = clock();
        _mergeInsertSort(_dequeNumbers, _dequeNumbers.begin(), _dequeNumbers.end());
        timeEnd = clock();
        return((double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3);
    }
    std::cout << ERR_NO_CONTAINER_MATCH << std::endl;
    _exitProgram();
    return (-1);
}

void    PmergeMe::_displaySortedArray(std::string container) {
    std::set<int>::iterator it;
    std::cout << "After:\t";

    if (container == "set") {
        for (it = _setNumbers.begin(); it != _setNumbers.end(); it++)
            std::cout << *it << " ";
    }
    else if (container == "list") {
        std::list<int>::iterator itList;
        for (itList = _listNumbers.begin(); itList != _listNumbers.end(); itList++)
            std::cout << *itList << " ";
    }
    else if (container == "deque") {
        std::deque<int>::iterator itDeque;
        for (itDeque = _dequeNumbers.begin(); itDeque != _dequeNumbers.end(); itDeque++)
            std::cout << *itDeque << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::_displayCompletionTime(std::string container, double sortTime) {
    if (container == "set") {
        std::cout << "Time to process a range of " << _arraySize << " elements with std::set\t: " << sortTime << " ms" << std::endl;
    }
    else if (container == "list") {
        std::cout << "Time to process a range of " << _arraySize << " elements with std::list\t: " << sortTime << " ms" << std::endl;
    }
    else if (container == "deque") {
        std::cout << "Time to process a range of " << _arraySize << " elements with std::deque\t: " << sortTime << " ms" << std::endl;
    }
}

// Public //
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
    delete[] _arrayNumbers;
}

void    PmergeMe::initialize(int argc, char *argv[]) {
    int number;
    _arraySize = argc - 1;
    _arrayNumbers = new int[_arraySize];

    for (int i = 1; i < argc; i++) {
        number = _assignNumber(argv[i]);
        if (_isNumberPositive(number))
            _arrayNumbers[i -1] = number;
        else
            _exitProgram();
    }
    //Duplicates
//    if (_areDuplicatesPresent())
//        _exitProgram();
    _displayStartingArray();
}

void    PmergeMe::set() {
    double  sortTime;

    sortTime = _timeToSort("set");
//    _displaySortedArray("set");
    _displayCompletionTime("set", sortTime);
}

void    PmergeMe::list() {
    double  sortTime;

    sortTime = _timeToSort("list");
    _displaySortedArray("list");
    _displayCompletionTime("list", sortTime);
}

void    PmergeMe::deque() {
    double  sortTime;

    sortTime = _timeToSort("deque");
//    _displaySortedArray("deque");
    _displayCompletionTime("deque", sortTime);
}
