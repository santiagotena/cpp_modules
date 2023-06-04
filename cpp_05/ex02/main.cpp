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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// PRESIDENTIAL PARDON FORM //" << std::endl;
    std::cout << partition << std::endl;
    {
        PresidentialPardonForm pardon("James Sunderland");
        PresidentialPardonForm pardonUnsigned(pardon);

        Bureaucrat bossMan("Boss", 1);
        Bureaucrat middleMan("Mid", 75);

        bossMan.signForm(pardon);
        bossMan.signForm(pardon);
        try {
            middleMan.signForm(pardonUnsigned);
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
        try {
            middleMan.executeForm(pardon);
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;

        bossMan.executeForm(pardonUnsigned);
        std::cout << std::endl;
        bossMan.executeForm(pardon);
        std::cout << pardon << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// ROBOTOMY FORM //" << std::endl;
    std::cout << partition << std::endl;
    {
        RobotomyRequestForm robo("Eddie");
        RobotomyRequestForm roboUnsigned(robo);

        Bureaucrat bossMan("Boss", 1);
        Bureaucrat middleMan("Mid", 75);

        bossMan.signForm(robo);
        bossMan.signForm(robo);
        try {
            middleMan.signForm(roboUnsigned);
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
        try {
            middleMan.executeForm(robo);
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;

        bossMan.executeForm(roboUnsigned);
        std::cout << std::endl;
        bossMan.executeForm(robo);
        std::cout << robo << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// SHRUBBERY FORM //" << std::endl;
    std::cout << partition << std::endl;
    {
        RobotomyRequestForm robo("Eddie");
        RobotomyRequestForm roboUnsigned(robo);

        Bureaucrat bossMan("Boss", 1);
        Bureaucrat middleMan("Mid", 75);

        bossMan.signForm(robo);
        bossMan.signForm(robo);
        try {
            middleMan.signForm(roboUnsigned);
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
        try {
            middleMan.executeForm(robo);
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;

        bossMan.executeForm(roboUnsigned);
        std::cout << std::endl;
        bossMan.executeForm(robo);
        std::cout << robo << std::endl;
    }



    std::cout << partition << std::endl;
    std::cout << "// ABSTRACT AFORM //" << std::endl;
    std::cout << partition << std::endl;
    {
//        AForm form(); //Will not compile
    }
    std::cout << partition << std::endl;
    std::cout << partition << std::endl;
    return (0);
}
