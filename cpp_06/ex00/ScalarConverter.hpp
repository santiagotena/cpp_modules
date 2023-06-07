/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:42:36 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/06 19:42:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

# define ERR_ARGC           "Error: Enter only one argument."
# define ERR_INVALID_INPUT  "Error: Invalid Input."

# define INT 0
# define FLOAT 1
# define DOUBLE 2
# define CHAR 3
# define PSEUDO 4
# define INVALID 5

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &src);
    virtual ~ScalarConverter();

public:
    static void convert(std::string const &input);
};

#endif