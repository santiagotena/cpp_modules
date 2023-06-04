/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:50:44 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/02 18:50:45 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// INC & DEC TESTS //" << std::endl;
    std::cout << partition << std::endl;
    try{
        Bureaucrat plancton;
        std::cout << plancton << std::endl;
        for (int i = 0; i < 5; i++) {
            plancton.incrementGrade();
            std::cout << plancton << std::endl;
        }
        for (int i = 0; i < 6; i++) {
            plancton.decrementGrade();
            std::cout << plancton << std::endl;
        }
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
    std::cout << std::endl;
    std::cout << partition << std::endl;
    std::cout << "// SET GRADE ABOVE //" << std::endl;
    std::cout << partition << std::endl;
    try{
        Bureaucrat("Xopo", 0);
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
    std::cout << std::endl;
    std::cout << partition << std::endl;
    std::cout << "// SET GRADE BELOW //" << std::endl;
    std::cout << partition << std::endl;
    try{
        Bureaucrat("Xopo", 420);
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
    std::cout << std::endl;
    std::cout << partition << std::endl;
    std::cout << "// COPY CONSTRUCTION //" << std::endl;
    std::cout << partition << std::endl;
    {
        Bureaucrat xopo("Xopo", 100);
        Bureaucrat topXopo(xopo);
        Bureaucrat bottomXopo = xopo;

        topXopo.incrementGrade();
        std::cout << topXopo << std::endl;

        bottomXopo.decrementGrade();
        std::cout << bottomXopo << std::endl;
    }
    std::cout << partition << std::endl;
    return (0);
}