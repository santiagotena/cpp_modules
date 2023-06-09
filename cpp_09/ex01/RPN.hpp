/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:33 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:34 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <stack>

# define ERR_SUM_OPERATOR           "Error: Not enough operands for operator '+'."
# define ERR_SUBS_OPERATOR          "Error: Not enough operands for operator '-'."
# define ERR_MULT_OPERATOR          "Error: Not enough operands for operator '*'."
# define ERR_DIV_OPERATOR           "Error: Not enough operands for operator '/'."
# define ERR_DIV_BY_ZERO            "Error: Cannot divide by zero."
# define ERR_INVALID_INPUT          "Error: Invalid element in input."
# define ERR_INVALID_NUMBER         "Error: Use numbers with values between -9 and 9."
# define ERR_NOT_ENOUGH_OPERATORS   "Error: Not enough operators provided."
# define ERR_ARGC                   "Error: Input a string of operations only."
# define INPUT_EXAMPLE              "Example: ./RPN \"7 7 * 7 -\""

class RPN {
private:
    std::stack<int>             _numbers;
    std::vector<std::string>    _elements;

    RPN(RPN &src);
    RPN &operator=(RPN &src);

    void                        _splitInput(char input[]);
    std::vector<std::string>    _split(const std::string &str, char delimiter);
    void                        _processElements();
    bool                        _isOperatorNext(std::string element);
    bool                        _isOperationPossible(std::string element);
    void                        _performOperations(std::string element);
    int                         _extractNextNumber(std::string element);
    bool                        _isNumberValid(int number);
    void                        _displayResult();

public:
    RPN();
    virtual ~RPN();

    void    calculate(char input[]);
};

#endif