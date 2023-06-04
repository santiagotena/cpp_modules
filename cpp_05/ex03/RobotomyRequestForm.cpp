/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:37:40 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/04 00:37:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
        AForm::AForm("Robotomy Request Form",
                     72,
                     45,
                     "undefined") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
        AForm::AForm("Robotomy Request Form",
                     72,
                     45,
                     target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):
        AForm::AForm(src.getName(),
                     src.getRequiredSignGrade(),
                     src.getRequiredExecuteGrade(),
                     src.getTarget())
{
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    setIsSigned(src.getIsSigned());
    setTarget(src.getTarget());
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExecuted(Bureaucrat const &bureaucrat) {
    if (!getIsSigned()) {
        std::cout << "This form is not yet signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= getRequiredExecuteGrade()) {
        std::time_t timeStamp = std::time(NULL);
        std::cout << "Robotomy procedure of subject " << getTarget() << " initialized..." << std::endl;
        srand(time(NULL));
        std::cout << "Robotomy outcome: " <<(timeStamp % 2 ? "Successful." : "Unsuccessful.") << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}
