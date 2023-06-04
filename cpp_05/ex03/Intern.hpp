/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:21:41 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/04 14:21:42 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(Intern const &src);
    Intern &operator=(Intern const &src);
    ~Intern();

    AForm *createNewPresidentialPardonForm(std::string target);
    AForm *createNewRobotomyRequestForm(std::string target);
    AForm *createNewShrubberyCreationForm(std::string target);

    AForm *makeForm(std::string form, std::string target);
};

#endif