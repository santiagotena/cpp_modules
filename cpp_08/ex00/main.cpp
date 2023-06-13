/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:55:58 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/12 17:55:59 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

void printEasyFindResult(bool result) {
    if (result)
        std::cout << "Value was found." << std::endl;
    else
        std::cout << "Value was not found." << std::endl;
}

int main() {
    std::vector<int>  vtr;

    for (int i = 0; i < 10; i++)
        vtr.push_back(i);

    printEasyFindResult(easyfind(vtr, 5));
    printEasyFindResult(easyfind(vtr, 42));
    printEasyFindResult(easyfind(vtr, 'a'));

    return (0);
}