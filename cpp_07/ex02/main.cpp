/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:15:46 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/09 11:49:23 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    std::string partition(30, '-');

    std::cout << partition << std::endl;
    std::cout << "// EMPTY ARRAY TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        Array<int>	array1(5);
        Array<int>	array2;

        int *array = new int();
        std::cout << *array << std::endl;
        delete array;

        std::cout << "array1 size: " << array1.size() << std::endl;
        try
        {
            for (int i = 0; i < 5; i++)
                std::cout << "array1 element[" << i << "]: " << array1[i] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "array2 size: " << array2.size() << std::endl;
        try
        {
            for (int i = 0; i < 5; i++)
                std::cout << "array2 element[" << i << "]: " << array2[i] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << partition << std::endl;
    std::cout << "// ... TEST //" << std::endl;
    std::cout << partition << std::endl;
    {

    }
    std::cout << partition << std::endl;
    return (0);
}