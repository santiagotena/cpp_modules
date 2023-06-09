/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:50:58 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/02 18:50:59 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Nameless"), _grade(BOTTOMGRADE) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
    setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name) {
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
    _grade = src._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Exception: The set grade is higher than the top position.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Exception: The set grade is below the bottom position.");
}

void Bureaucrat::setGrade(int grade) {
    if (grade < TOPGRADE)
        throw GradeTooHighException();
    if (grade > BOTTOMGRADE)
        throw GradeTooLowException();
    _grade = grade;
}

void Bureaucrat::incrementGrade() {
    setGrade(--_grade);
}

void Bureaucrat::decrementGrade() {
    setGrade(++_grade);
}

void Bureaucrat::signForm(Form &form) {
    if (form.getIsSigned()) {
        std::cout << "This form is already signed." << std::endl;
        return;
    }
    if (_grade <= form.getRequiredSignGrade()) {
        std::cout << _name << " signed " << form.getName() << "." << std::endl;
    } else {
        std::cout << _name << " could not sign " << form.getName() <<
        ". Clearance level is not high enough." << std::endl;
    }
    form.beSigned(*this);
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input)
{
    output << input.getName() << ", bureaucrat grade " << input.getGrade() << ".";
    return (output);
}
