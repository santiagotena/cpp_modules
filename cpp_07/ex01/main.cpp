/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:15:46 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/09 11:15:47 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main() {
    std::string partition(30, '-');

    char		chars[5] = {'a', 'b', 'c', 'd', 'e'};
    int			ints[5] = {1, 2, 5, 7, 10};
    char*		charptrs[5];
    int*		intptrs[5];

    for (int i = 0; i < 5; i++)
    {
        charptrs[i] = &chars[i];
        intptrs[i] = &ints[i];
    }

    std::cout << partition << std::endl;
    std::cout << "// CHAR TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        iter(chars, 5, print);
        std::cout << partition << std::endl;

        iter(&charptrs, 5, print);
        iter(charptrs, 5, print);
    }
    std::cout << partition << std::endl;
    std::cout << "// INT TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        iter(ints, 5, print);
        std::cout << partition << std::endl;

        iter(ints, 5, square);
        iter(ints, 5, print);
        std::cout << partition << std::endl;

        iter(intptrs, 5, print);
    }
    std::cout << partition << std::endl;
    return (0);
}