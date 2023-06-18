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
    //Sort set (Populate)
    timeEnd = clock();
    setTime = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3;
    //Print set
    std::cout << "After:\t";
    std::cout << std::endl;

    //Populate list
    timeStart = clock();
    //Sort list
    timeEnd = clock();
    listTime = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3;
    //Print list
    std::cout << "After:\t";
    std::cout << std::endl;

    //Populate deque
    timeStart = clock();
    //Sort deque
    timeEnd = clock();
    dequeTime = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC * 1e3;
    //Print deque
    std::cout << "After:\t";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::set: " << setTime << " ms" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::list: " << listTime << " ms" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque: " << dequeTime << " ms" << std::endl;
    return (0);
}