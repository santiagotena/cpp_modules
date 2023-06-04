/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:37:23 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/03 13:37:24 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    std::string const   _name;
    bool                _isSigned;
    int const           _requiredSignGrade;
    int const           _requiredExecuteGrade;

    void                _checkFormGrades();

public:
    Form();
    Form(std::string const &name, int const requiredSignGrade, int const requiredExecuteGrade);
    Form(Form const &src);
    Form &operator=(Form const &src);
    ~Form();

    std::string const   getName() const;
    bool                getIsSigned() const;
    int const           getRequiredSignGrade() const;
    int const           getRequiredExecuteGrade() const;

    void                beSigned(Bureaucrat const &bureaucrat);

    class GradeTooHighException: public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &output, Form const &input);

# endif