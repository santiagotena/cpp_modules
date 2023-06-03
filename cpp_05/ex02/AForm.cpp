/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:37:21 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/03 13:37:22 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void AForm::_checkFormGrades() {
    if (_requiredSignGrade < TOPGRADE || _requiredExecuteGrade < TOPGRADE)
        throw AForm::GradeTooHighException();
    if (_requiredSignGrade > BOTTOMGRADE || _requiredExecuteGrade > BOTTOMGRADE)
        throw AForm::GradeTooLowException();

}

AForm::AForm():
    _name("Untitled Form"),
    _isSigned(false),
    _requiredSignGrade(TOPGRADE),
    _requiredExecuteGrade(TOPGRADE) {}

AForm::AForm(std::string const &name, int const requiredSignGrade, int const requiredExecuteGrade) :
    _name(name),
    _isSigned(false),
    _requiredSignGrade(requiredSignGrade),
    _requiredExecuteGrade(requiredExecuteGrade)
{
    _checkFormGrades();
}

AForm::AForm(AForm const &src):
    _name(src._name),
    _isSigned(src._isSigned),
    _requiredSignGrade(src._requiredSignGrade),
    _requiredExecuteGrade(src._requiredExecuteGrade)
{
    *this = src;
}

AForm &AForm::operator=(AForm const &src) {
    _isSigned = src._isSigned;
    return (*this);
}

AForm::~AForm() {}

std::string const   AForm::getName() const {return (_name);}

bool                AForm::getIsSigned() const {return(_isSigned);}

int const           AForm::getRequiredSignGrade() const {return(_requiredSignGrade);}

int const           AForm::getRequiredExecuteGrade() const {return(_requiredExecuteGrade);}

void                AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (_isSigned) {
        std::cout << "This form is already signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= _requiredSignGrade)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("The grade is higher than the top position.");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("The grade is below the bottom position.");
}

std::ostream &operator<<(std::ostream &output, AForm const &input)
{
    std::string signatureState;

    signatureState = input.getIsSigned() ? "Present" : "Absent";
    output << "Form name: " << input.getName() << "." << std::endl;
    output << "Signature: " << signatureState << "." << std::endl;
    output << "Required Sign Grade: " << input.getRequiredSignGrade() << "." << std::endl;
    output << "Required Execute Grade: " << input.getRequiredExecuteGrade() << ".";
    return (output);
}
