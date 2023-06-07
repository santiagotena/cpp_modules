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

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    return(*this);
}

ScalarConverter::~ScalarConverter() {}

void    displayConversion(char character, bool isIntPossible, int integerNumber, float floatNumber, double doubleNumber)
{
    if (character > 32 && character < 127)
        std::cout <<    "char: '" <<  character << "' "<< std::endl <<
                        "int: " << integerNumber << std::endl <<
                        "float: " << std::fixed << std::setprecision(1) << floatNumber <<"f" << std::endl <<
                        "double: " << std::fixed << std::setprecision(1) << doubleNumber << std::endl;
    else if (isIntPossible)
        std::cout <<    "char: non displayable" << std::endl <<
                        "int: " << integerNumber << std::endl <<
                        "float: " << std::fixed << std::setprecision(1) << floatNumber <<"f" << std::endl <<
                        "double: " << std::fixed << std::setprecision(1) << doubleNumber << std::endl;
    else
        std::cout <<    "char: impossible" << std::endl <<
                        "int: impossible" << std::endl <<
                        "float: " << std::fixed << std::setprecision(1) << floatNumber <<"f" << std::endl <<
                        "double: " << std::fixed << std::setprecision(1) << doubleNumber << std::endl;
}

void    handleDouble(double doubleNumber)
{
    float floatNumber = static_cast<float>(doubleNumber);
    char character = static_cast<char>(doubleNumber);
    int integerNumber = static_cast<int>(doubleNumber);
    displayConversion(character, 1, integerNumber, floatNumber, doubleNumber);
}

void    handleFloat(float floatNumber)
{
    char character = static_cast<char>(floatNumber);
    double doubleNumber = static_cast<double>(floatNumber);
    int integerNumber = static_cast<int>(floatNumber);
    displayConversion(character, 1, integerNumber, floatNumber, doubleNumber);
}

void    handleInt(int integerNumber)
{
    char character = static_cast<char>(integerNumber);
    float floatNumber = static_cast<float>(integerNumber);
    double doubleNumber = static_cast<double>(integerNumber);
    displayConversion(character, 1, integerNumber, floatNumber, doubleNumber);

}

void    handlePseudo(std::string input)
{
    float floatNumber = static_cast<float>(atof(input.c_str()));
    double doubleNumber = static_cast<double>(floatNumber);
    int integerNumber = static_cast<int>(floatNumber);
    char character = static_cast<char>(floatNumber);
    displayConversion(character, 0, integerNumber, floatNumber, doubleNumber);
}

void    handleChar(char character)
{
    int integerNumber = static_cast<int>(character);
    float floatNumber = static_cast<float>(character);
    double doubleNumber = static_cast<double>(character);
    displayConversion(character, 1, integerNumber, floatNumber, doubleNumber);
}

int     findType(std::string s)
{
    if (s.length() == 1 && !isdigit(s.at(0)))
        return (CHAR);
    if (s == "-inf" || s == "+inf" || s == "inf" || s == "nan" || s == "-inff" || s == "+inff" || s == "nanf")
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
            handleChar(input[0]);
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
