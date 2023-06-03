/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:37:23 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/03 13:37:24 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    std::string const   _name;
    bool                _isSigned;
    int const           _requiredSignGrade;
    int const           _requiredExecuteGrade;

    void                _checkFormGrades();

public:
    AForm();
    AForm(const std::string &name, const int requiredSignGrade, const int requiredExecuteGrade);
    AForm(AForm const &src);
    AForm &operator=(AForm const &src);
    ~AForm();

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

std::ostream &operator<<(std::ostream &output, AForm const &input);

# endif