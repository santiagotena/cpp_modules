/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:34 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:35 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &src) {
    (void)src;
}

RPN &RPN::operator=(RPN const &src)
{
    (void)src;
    return(*this);
}

RPN::~RPN() {}

bool    RPN::_performOperations(std::string buffer) {
    int operand;
    int result;

    if (buffer == "+") {
        if (_numbers.size() >= 2) {
            operand = _numbers.top();
            _numbers.pop();
            result = operand + _numbers.top();
            _numbers.pop();
            _numbers.push(result);
            return (true);
        }
        std::cout << "Error: Not enough operands for operator '+'." << std::endl;
        exit(-1);
    }
    else if (buffer == "-") {
        if (_numbers.size() >= 2) {
            operand = _numbers.top();
            _numbers.pop();
            result = operand - _numbers.top();
            _numbers.pop();
            _numbers.push(result);
            return (true);
        }
        std::cout << "Error: Not enough operands for operator '-'." << std::endl;
        exit(-1);
    }
    else if (buffer == "*") {
        if (_numbers.size() >= 2) {
            operand = _numbers.top();
            _numbers.pop();
            result = operand * _numbers.top();
            _numbers.pop();
            _numbers.push(result);
            return (true);
        }
        std::cout << "Error: Not enough operands for operator '*'." << std::endl;
        exit(-1);
    }
    else if (buffer == "/") {
        if (_numbers.size() >= 2) {
            operand = _numbers.top();
            _numbers.pop();
            result = operand / _numbers.top();
            _numbers.pop();
            _numbers.push(result);
            return(true);
        }
        std::cout << "Error: Not enough operands for operator '/'." << std::endl;
        exit(-1);
    }
    return (false);
}

void    RPN::calculate(char *input[]) {
    int number;
    std::string buffer;

    int i = 0;
    while (input[i]) {
        buffer = input[i];
        if (_performOperations(buffer))
            continue;
        number = std::atoi(input[i]);
        if (!std::isdigit(number)) {
            std::cout << "Error: Invalid element in input." << std::endl;
            exit(-1);
        }
        if (number > 9 || number < -9) {
            std::cout << "Error: Use numbers with values between -9 and 9." << std::endl;
            exit(-1);
        }
        _numbers.push(number);
    i++;
    }
    if (_numbers.size() > 1) {
        std::cout << "Not enough operators provided." << std::endl;
        exit(-1);
    } else {
        std::cout << _numbers.top() << std::endl;
    }
}
