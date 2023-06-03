/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:50:56 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/02 18:50:57 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# include <iostream>
# define TOPGRADE 1
# define BOTTOMGRADE 150

class Bureaucrat {
private:
    std::string const   _name;
    int                 _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const &src);
    ~Bureaucrat();

    std::string getName() const;
    int         getGrade() const;
    void        setGrade(int grade);
    void        incrementGrade();
    void        decrementGrade();

    class GradeAboveTopException: public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeBelowBottomException: public std::exception
    {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input);

#endif