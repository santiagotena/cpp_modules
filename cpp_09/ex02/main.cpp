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
    PmergeMe sorter;

    sorter.initialize(argc, argv);
    sorter.list();
    sorter.deque();
    sorter.set();
    return (0);
}