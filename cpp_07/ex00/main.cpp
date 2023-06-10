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
#include "whatever.hpp"

int main() {
    std::string partition(30, '-');

    std::cout << partition << std::endl;
    std::cout << "// BASE TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        int a = 2;
        int b = 3;
        swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// DOUBLE //" << std::endl;
    std::cout << partition << std::endl;
    {
        double a = 2;
        double b = 3;
        swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
    }
    std::cout << partition << std::endl;
    return (0);
}