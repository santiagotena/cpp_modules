/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:24:10 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/13 12:24:11 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    std::string partition(30, '-');

    std::cout << partition << std::endl;
    std::cout << "// BASE TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// 15 000 TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Span sp = Span(20000);

        sp.addNumberRange(25000, 10000);
        sp.addNumberRange(10000, 25000);
        sp.addNumber(0);
        sp.addNumber(99999);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// SAME NUMBER TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Span sp = Span(5);

        sp.addNumber(99999);
        sp.addNumber(99999);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// EXCEPTION TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        try {
            Span sp = Span(2);

            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
        }
        catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            Span sp = Span(5);

            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            Span sp = Span(5);

            sp.addNumber(6);
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << partition << std::endl;
    return (0);
}
