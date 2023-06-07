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

void displayConversion(char charachter, bool isPossibleInt, int integer, float floatNumber, double doubleNumber)
{
    if (charachter > 32 && charachter < 127)
        std::cout <<    "char: '" <<  charachter << "' "<< std::endl <<
                        "int: " << integer << std::endl <<
                        "float: " << std::fixed << std::setprecision(1) << floatNumber <<"f" << std::endl <<
                        "double: " << std::fixed << std::setprecision(1) << doubleNumber << std::endl;
    else if (isPossibleInt)
        std::cout <<    "char: not displayable" << std::endl <<
                        "int: " << integer << std::endl <<
                        "float: " << std::fixed << std::setprecision(1) << floatNumber <<"f" << std::endl <<
                        "double: " << std::fixed << std::setprecision(1) << doubleNumber << std::endl;
    else
        std::cout <<    "char: impossible" << std::endl <<
                        "int: impossible" << std::endl <<
                        "float: " << std::fixed << std::setprecision(1) << floatNumber <<"f" << std::endl <<
                        "double: " << std::fixed << std::setprecision(1) << doubleNumber << std::endl;
}

void handleInt(int integer)
{
    float floatNumber = static_cast<float>(integer);
    double doubleNumber = static_cast<double>(integer);
    char charachter = static_cast<char>(integer);
    displayConversion(charachter, 1, integer, floatNumber, doubleNumber);

}

void handleFloat(float floatNumber)
{
    double doubleNumber = static_cast<double>(floatNumber);
    char charachter = static_cast<char>(floatNumber);
    if (floatNumber > INT_MAX || floatNumber < INT_MIN)
    {
        int integer = INT_MIN;
        displayConversion(charachter, 0, integer, floatNumber, doubleNumber);
        return ;
    }
    int integer = static_cast<int>(floatNumber);
    displayConversion(charachter, 1, integer, floatNumber, doubleNumber);
}

void handleDouble(double doubleNumber)
{
    float floatNumber = static_cast<float>(doubleNumber);
    char charachter = static_cast<char>(doubleNumber);
    if (doubleNumber > INT_MAX || doubleNumber < INT_MIN)
    {
        int integer = INT_MIN;
        displayConversion(charachter, 0, integer, floatNumber, doubleNumber);
        return ;
    }
    int integer = static_cast<int>(doubleNumber);
    displayConversion(charachter, 1, integer, floatNumber, doubleNumber);
}

void handleChar(char charachter)
{
    float floatNumber = static_cast<float>(charachter);
    double doubleNumber = static_cast<double>(charachter);
    int integer = static_cast<int>(charachter);
    displayConversion(charachter, 1, integer, floatNumber, doubleNumber);
}

void handlePseudo(std::string str)
{
    float floatNumber = static_cast<float>(atof(str.c_str()));
    double doubleNumber = static_cast<double>(floatNumber);
    int integer = INT_MIN; // this was the behavior of cpp itself, when trying to cast inf to int. but acc to subj, I will only print "impossible".
    char charachter = static_cast<char>(floatNumber);
    displayConversion(charachter, 0, integer, floatNumber, doubleNumber);
}

int    findType(std::string s)
{
    if (s.length() == 1 && !isdigit(s.at(0)))
        return (CHAR);
    if (s == "-inf" || s == "+inff" || s == "-inf" || s == "+inf" || s == "nan" )
        return(PSEUDO);
    for(size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s.at(i)) && s.at(i) != '.' && s.at(i) != 'f' && s.at(i) != '-' && s.at(i) != '+')
            return (INVALID);
        else if (i != 0 && (s[i] == '+' || s[i] == '-'))
            return (INVALID);
    }
    if (s.find('.') != std::string::npos)
    {
        if (s.find_first_of('.') != s.find_last_of('.') || s.find_first_of('f') != s.find_last_of('f'))
            return (INVALID);
        if (s.find('f') == s.length() - 1)
            return (FLOAT);
        if (s.find('f') != std::string::npos)
            return(INVALID);
        return (DOUBLE);
    }
    if (s.find('f') != std::string::npos)
        return(INVALID);
    long tmp = atol(s.c_str());
    if (tmp > std::numeric_limits<int>::max() ||  tmp < std::numeric_limits<int>::min())
        return (DOUBLE);
    return (INT);
}

void    ScalarConverter::convert(std::string const &input)
{
    int type= findType(input);
    switch (type)
    {
        case CHAR:
            handleChar(input.at(0));
            break;
        case PSEUDO:
            handlePseudo(input);
            break;
        case INT:
            handleInt(atoi(input.c_str()));
            break;
        case FLOAT:
            handleFloat(atof(input.c_str()));
            break;
        case DOUBLE:
            handleDouble(atof(input.c_str()));
            break;
        case INVALID:
            std::cerr << ERR_INVALID_INPUT << std::endl;
            return ;
    }
}
