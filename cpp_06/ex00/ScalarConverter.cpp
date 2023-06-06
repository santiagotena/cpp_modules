/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:42:38 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/06 19:42:39 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int    findType(std::string s)
{
    if (s.length() == 1 && !isdigit(s.at(0)))
        return (CHAR);
    if (s == "-inf" || s == "+inff" || s == "-inf" || s == "+inf" || s == "nan" )
        return(PSEUDO);
    for(size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s.at(i)) && s.at(i) != '.' && s.at(i) != 'f' && s.at(i) != '-' && s.at(i) != '+')
            return (NON);
        else if (i != 0 && (s[i] == '+' || s[i] == '-'))
            return (NON);
    }
    if (s.find('.') != std::string::npos)
    {
        if (s.find_first_of('.') != s.find_last_of('.') || s.find_first_of('f') != s.find_last_of('f'))
            return (NON);
        if (s.find('f') == s.length() - 1)
            return (FLOAT);
        if (s.find('f') != std::string::npos)
            return(NON);
        return (DOUBLE);
    }
    if (s.find('f') != std::string::npos)
        return(NON);
    return (INT);
}

void print_stuff(char char_, bool valid, int int_, float float_, double double_)
{
    if (char_ > 32 && char_ < 127)
        std::cout << "char: '" <<  char_ << "' "<< "\nint: " << int_ << "\nfloat: " << std::fixed << std::setprecision(1) << float_ <<"f" << "\ndouble: " << std::fixed << std::setprecision(1) << double_ << std::endl;
    else if (valid)
        std::cout << "char: not displayable\n" << "int: " << int_ << "\nfloat: " << std::fixed << std::setprecision(1) << float_ << "f" <<"\ndouble: "  << std::fixed << std::setprecision(1) << double_ << std::endl;
    else
    std::cout << "char: impossible\n" << "int: " << "impossible" << "\nfloat: " << std::fixed << std::setprecision(1) << float_ << "f" << "\ndouble: " << std::fixed << std::setprecision(1) << double_ << std::endl;
}
void handle_int(int int_)
{
    float float_ = static_cast<float>(int_);
    double double_ = static_cast<double>(int_);
    char char_ = static_cast<char>(int_);
    print_stuff(char_, 1, int_, float_, double_);

}

void handle_float(float float_)
{
    double double_ = static_cast<double>(float_);
    char char_ = static_cast<char>(float_);
    if (float_ > INT_MAX || float_ < INT_MIN)
    {
        int int_ = INT_MIN;
        print_stuff(char_, 0, int_, float_, double_);
        return ;
    }
    int int_ = static_cast<int>(float_);
    print_stuff(char_, 1, int_, float_, double_);
}

void handle_double(double double_)
{
    float float_ = static_cast<float>(double_);
    char char_ = static_cast<char>(double_);
    if (double_ > INT_MAX || double_ < INT_MIN)
    {
        int int_ = INT_MIN;
        print_stuff(char_, 0, int_, float_, double_);
        return ;
    }
    int int_ = static_cast<int>(double_);
    print_stuff(char_, 1, int_, float_, double_);
}

void handle_char(char char_)
{
    float float_ = static_cast<float>(char_);
    double double_ = static_cast<double>(char_);
    int int_ = static_cast<int>(char_);
    print_stuff(char_, 1, int_, float_, double_);
}

void handle_infs(std::string str)
{
    float float_ = static_cast<float>(atof(str.c_str()));
    double double_ = static_cast<double>(float_);
    int int_ = INT_MIN; // this was the behavior of cpp itself, when trying to cast inf to int. but acc to subj, I will only print "impossible".
    char char_ = static_cast<char>(float_);
    print_stuff(char_, 0, int_, float_, double_);
}

void    ScalarConverter::convert(std::string const &str)
{
    int type_= findType(str);
    long tmp = atol(str.c_str());
    if (tmp > std::numeric_limits<int>::max() ||  tmp < std::numeric_limits<int>::min()) //this is to protect int_ from having big numbers
        type_ = FLOAT;
    switch (type_)
    {
        case INT:
            handle_int(atoi(str.c_str()));
            break;
        case FLOAT:
            handle_float(atof(str.c_str()));
            break;
        case DOUBLE:
            handle_double(atof(str.c_str()));
            break;
        case CHAR:
            handle_char(str.at(0));
            break;
        case PSEUDO:
            handle_infs(str);
            break;
        case NON:
            std::cerr << "error! invalid string input." << std::endl;
            return ;
    }
}
