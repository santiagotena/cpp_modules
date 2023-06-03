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
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// SIGNED GRADES LIMITS //" << std::endl;
    std::cout << partition << std::endl;
    {
        AForm datform("Test Form", 98, 23);
        std::cout << datform << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// SIGNED GRADES LIMITS //" << std::endl;
    std::cout << partition << std::endl;
    {
        try
        {
            AForm temp("test", 151, 23);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            AForm temp("test", 0, 23);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << partition << std::endl;
    std::cout << "// EXECUTION GRADES LIMITS //" << std::endl;
    std::cout << partition << std::endl;
    {
        try
        {
            AForm temp("test", 25, 151);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            AForm temp("test", 25, 0);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << partition << std::endl;
    std::cout << "// FORM SIGNING //" << std::endl;
    std::cout << partition << std::endl;
    {
        AForm form("Draft Form", 98, 23);
        AForm form2(form);
        std::cout << form << std::endl;
        std::cout << std::endl;
        std::cout << form2 << std::endl;
        std::cout << std::endl;

        Bureaucrat tom("Tom", 98);
        Bureaucrat jerry("Jerry", 99);
        tom.signForm(form);
        std::cout << form << std::endl;
        std::cout << std::endl;
        jerry.signForm(form2);
        std::cout << form2 << std::endl;
    }
    std::cout << partition << std::endl;
    return (0);
}
