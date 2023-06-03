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

int main(){
    try{
        Bureaucrat plancton;
        for (int i = 0; i < 5; i++) {
            plancton.incrementGrade();
            std::cout << plancton;
        }
        for (int i = 0; i < 5; i++) {
            plancton.decrementGrade();
            std::cout << plancton;
        }
        Bureaucrat("Xopo", 420);
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
}