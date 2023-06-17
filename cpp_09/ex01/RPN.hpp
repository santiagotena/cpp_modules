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
# include <stack>

class RPN {
private:
    std::stack<int> _numbers;

    bool    _performOperations(std::string buffer);

public:
    RPN();
    RPN(RPN const &src);
    RPN &operator=(RPN const &src);
    virtual ~RPN();

    void    calculate(char *input[]);
};

#endif