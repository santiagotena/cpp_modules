/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:37:21 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/03 13:37:22 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void Form::_checkFormGrades() {
    if (_requiredSignGrade < TOPGRADE || _requiredExecuteGrade < TOPGRADE)
        throw Form::GradeTooHighException();
    if (_requiredSignGrade > BOTTOMGRADE || _requiredExecuteGrade > BOTTOMGRADE)
        throw Form::GradeTooLowException();

}

Form::Form():
    _name("Untitled Form"),
    _isSigned(false),
    _requiredSignGrade(TOPGRADE),
    _requiredExecuteGrade(TOPGRADE) {}

Form::Form(std::string const &name, int const requiredSignGrade, int const requiredExecuteGrade) :
    _name(name),
    _isSigned(false),
    _requiredSignGrade(requiredSignGrade),
    _requiredExecuteGrade(requiredExecuteGrade)
{
    _checkFormGrades();
}

Form::Form(Form const &src):
    _name(src._name),
    _isSigned(src._isSigned),
    _requiredSignGrade(src._requiredSignGrade),
    _requiredExecuteGrade(src._requiredExecuteGrade)
{
    *this = src;
}

Form &Form::operator=(Form const &src) {
    _isSigned = src._isSigned;
    return (*this);
}

Form::~Form() {}

std::string const   Form::getName() const {return (_name);}

bool                Form::getIsSigned() const {return(_isSigned);}

int const           Form::getRequiredSignGrade() const {return(_requiredSignGrade);}

int const           Form::getRequiredExecuteGrade() const {return(_requiredExecuteGrade);}

void                Form::beSigned(Bureaucrat const &bureaucrat) {
    if (_isSigned) {
        std::cout << "This form is already signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= _requiredSignGrade)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("The grade is higher than the top position.\n");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("The grade is below the bottom position.\n");
}

std::ostream &operator<<(std::ostream &output, Form const &input)
{
    std::string signatureState;

    signatureState = input.getIsSigned() ? "Present" : "Absent";
    output << "Form name: " << input.getName() << "." << std::endl;
    output << "Signature: " << signatureState << "." << std::endl;
    output << "Required Sign Grade: " << input.getRequiredSignGrade() << "." << std::endl;
    output << "Required Execute Grade: " << input.getRequiredExecuteGrade() << ".";
    return (output);
}
