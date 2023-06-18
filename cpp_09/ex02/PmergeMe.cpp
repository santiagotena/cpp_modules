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
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe &src) {*this = src;}

//PmergeMe    &PmergeMe::operator=(PmergeMe &src) {
//    if (src._container == "set") {
//        _container = src._container;
//        //Deep copy
//        return (*this);
//    }
//    else if (src._container == "list") {
//        _container = src._container;
//        //Deep copy
//        return (*this);
//    }
//    else if (src._container == "deque") {
//        _container = src._container;
//        //Deep copy
//        return (*this);
//    } else {
//        std::cerr << "Error: Invalid assignment." << std::endl;
//        exit(-1);
//    }
//}

// Public //
PmergeMe::PmergeMe(std::string container) {
    if (container == "set")
        _container = "set";
    else if (container == "list")
        _container = "list";
    else if (container == "deque")
        _container = "deque";
    else {
        std::cerr << "Error: Invalid container type." << std::endl;
        exit(-1);
    }
}

PmergeMe::~PmergeMe() {}
