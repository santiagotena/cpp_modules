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
    for (int i = 0; i < (argc - 2); i++) {
        for (int j = (i + 1); j < (argc - 1); j++) {
            if (arrayNumbers[i] == arrayNumbers[j]) {
                std::cout << "Error: No duplicates are allowed." << std::endl;
                exit(-1);
            }
        }
    }

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
    //Sort list
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
    //Sort deque
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