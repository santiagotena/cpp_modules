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

// Private //
RPN::RPN(RPN &src) {
    *this = src;
}

RPN &RPN::operator=(RPN &src)
{
    while (!_numbers.empty()) {
        _numbers.pop();
    }
    std::stack<int> temp;
    while (!src._numbers.empty()) {
        temp.push(src._numbers.top());
        src._numbers.pop();
    }
    while (!temp.empty()) {
        _numbers.push(temp.top());
        src._numbers.push(temp.top());
        temp.pop();
    }
    return(*this);
}

bool    RPN::_performOperations(std::string element) {
    int operand;
    int result;

    if (element == "+") {
        if (_numbers.size() >= 2) {
            operand = _numbers.top();
            _numbers.pop();
            result = _numbers.top() + operand;
            _numbers.pop();
            _numbers.push(result);
            return (true);
        }
        std::cout << ERR_SUM_OPERATOR << std::endl;
        exit(-1);
    }
    else if (element == "-") {
        if (_numbers.size() >= 2) {
            operand = _numbers.top();
            _numbers.pop();
            result = _numbers.top() - operand;
            _numbers.pop();
            _numbers.push(result);
            return (true);
        }
        std::cout << ERR_SUBS_OPERATOR << std::endl;
        exit(-1);
    }
    else if (element == "*") {
        if (_numbers.size() >= 2) {
            operand = _numbers.top();
            _numbers.pop();
            result = _numbers.top() * operand;
            _numbers.pop();
            _numbers.push(result);
            return (true);
        }
        std::cout << ERR_MULT_OPERATOR << std::endl;
        exit(-1);
    }
    else if (element == "/") {
        if (_numbers.size() >= 2) {
            operand = _numbers.top();
            _numbers.pop();
            result = _numbers.top() / operand;
            _numbers.pop();
            _numbers.push(result);
            return(true);
        }
        std::cout << ERR_DIV_OPERATOR << std::endl;
        exit(-1);
    }
    return (false);
}

std::vector<std::string>    RPN::_split(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;

    while (std::getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }
    return (tokens);
}

// Public //
RPN::RPN() {}

RPN::~RPN() {}

void    RPN::calculate(char input[]) {
    int number;
    std::string inputStr = static_cast<std::string>(input);
    std::vector<std::string> elements = _split(inputStr, ' ');

    std::vector<std::string>::iterator it;
    for (it = elements.begin(); it != elements.end(); it++) {
        if (_performOperations(*it))
            continue;

        std::istringstream iss(*it);
        if (!(iss >> number)) {
            std::cout << ERR_INVALID_INPUT << std::endl;
            exit (1);
        }
        if (number > 9 || number < -9) {
            std::cout << ERR_INVALID_NUMBER << std::endl;
            exit(-1);
        }

        _numbers.push(number);
    }
    if (_numbers.size() > 1) {
        std::cout << ERR_NOT_ENOUGH_OPERATORS << std::endl;
        exit(-1);
    } else {
        std::cout << _numbers.top() << std::endl;
    }
}
