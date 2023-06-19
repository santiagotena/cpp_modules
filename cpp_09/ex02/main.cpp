/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:32 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:33 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container, typename Iterator>
void merge(Container& cont, Iterator low, Iterator mid, Iterator high) {
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

// Function to perform merge-insert sort
template <typename Container, typename Iterator>
void mergeInsertSort(Container& cont, Iterator low, Iterator high) {
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
            mergeInsertSort(cont, low, mid);
            mergeInsertSort(cont, mid, high);

            // Merge the sorted halves
            merge(cont, low, mid, high);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Error: Provide more than one element to sort." << std::endl;
        return (-1);
    }

    PmergeMe setSort("set");
    PmergeMe listSort("list");
    PmergeMe dequeSort("deque");
    clock_t	timeStart;
    clock_t timeEnd;
    double setTime, listTime, dequeTime;
    int number;
    int arrayNumbers[argc - 1];

    for (int i = 1; i < argc; i++) {

        std::istringstream iss(argv[i]);
        if (!(iss >> number)) {
            std::cout << "Error: Only positive integers are allowed." << std::endl;
            exit(-1);
        }

        if (number > 0)
            arrayNumbers[i -1] = number;
        else {
            std::cout << "Error: Only positive integers are allowed." << std::endl;
            exit(-1);
        }

    }

    //Duplicates
//    for (int i = 0; i < (argc - 2); i++) {
//        for (int j = (i + 1); j < (argc - 1); j++) {
//            if (arrayNumbers[i] == arrayNumbers[j]) {
//                std::cout << "Error: No duplicates are allowed." << std::endl;
//                exit(-1);
//            }
//        }
//    }

    std::cout << "Before:\t";
    for (int i = 0; i < argc -1; i++) {
        std::cout << arrayNumbers[i] << " ";
    }
    std::cout << std::endl;

    timeStart = clock();
    if (!(setSort._container == "set")) {
        std::cout << "Error: Object type needs to match the container." << std::endl;
        return (-1);
    }
    for (int i = 0; i < argc -1; i++)
        setSort.setNumbers.insert(arrayNumbers[i]);
    timeEnd = clock();
    setTime = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3;

    std::set<int>::iterator it;
    std::cout << "After:\t";
    for (it = setSort.setNumbers.begin(); it != setSort.setNumbers.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    if (!(listSort._container == "list")) {
        std::cout << "Error: Object type needs to match the container." << std::endl;
        return (-1);
    }
    for (int i = 0; i < argc -1; i++)
        listSort.listNumbers.push_back(arrayNumbers[i]);
    timeStart = clock();
    mergeInsertSort(listSort.listNumbers, listSort.listNumbers.begin(), listSort.listNumbers.end());
    timeEnd = clock();
    listTime = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3;
    std::list<int>::iterator itList;
    std::cout << "After:\t";
    for (itList = listSort.listNumbers.begin(); itList != listSort.listNumbers.end(); itList++)
        std::cout << *itList << " ";
    std::cout << std::endl;

    if (!(dequeSort._container == "deque")) {
        std::cout << "Error: Object type needs to match the container." << std::endl;
        return (-1);
    }
    for (int i = 0; i < argc -1; i++)
        dequeSort.dequeNumbers.push_back(arrayNumbers[i]);
    timeStart = clock();
    mergeInsertSort(dequeSort.dequeNumbers, dequeSort.dequeNumbers.begin(), dequeSort.dequeNumbers.end());
    timeEnd = clock();
    dequeTime = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3;
    std::deque<int>::iterator itDeque;
    std::cout << "After:\t";
    for (itDeque = dequeSort.dequeNumbers.begin(); itDeque != dequeSort.dequeNumbers.end(); itDeque++)
        std::cout << *itDeque << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::set\t: " << setTime << " ms" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::list\t: " << listTime << " ms" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque\t: " << dequeTime << " ms" << std::endl;
    return (0);
}