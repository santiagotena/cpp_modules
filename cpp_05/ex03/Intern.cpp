/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:21:43 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/04 14:21:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &src) {*this = src;}

Intern &Intern::operator=(Intern const &src) {
    (void) src;
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::createNewPresidentialPardonForm(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::createNewRobotomyRequestForm(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::createNewShrubberyCreationForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target) {
    std::string formIndex[] =
    {
    "presidential pardon",
    "robotomy request",
    "shrubbery creation"
    };
    AForm *(Intern:: *formProduction[])(std::string target) =
    {
            &Intern::createNewPresidentialPardonForm,
            &Intern::createNewRobotomyRequestForm,
            &Intern::createNewShrubberyCreationForm
    };
    for (int i = 0; i < 3; i++) {
        if (formIndex[i] == form) {
            std::cout << "Intern creates one " << form << " form." << std::endl;
            return (this->*formProduction[i])(target);
        }
    }
    std::cout << "Could not find form. Available forms are: "
                 "<shrubbery creation>, <robotomy request> and <presidential pardon>."
                 << std::endl;
    return (NULL);
}