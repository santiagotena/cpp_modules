/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:37 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <ostream>
# include <fstream>
# include <map>
# include "Date.hpp"

# define ERR_ARGC               "Error: could not open file."
# define ERR_REFERENCE_FILE     "Error: could not open reference file."
# define ERR_INPUT_FILE         "Error: could not open file."
# define ERR_NOT_POSITIVE_NUM   "Error: not a positive number."
# define ERR_TOO_LARGE_NUM      "Error: too large a number."

class Date;

class BitcoinExchange {
private:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange &src);
    BitcoinExchange &operator=(BitcoinExchange &src);

    Date    _createDate(std::string date);
    void    _findRate(double amount, Date time);
    void    _printResult(double value, double amount, Date time);

public:
    std::map <Date, double> bitcoinDB;

    BitcoinExchange(std::string referenceFile);
    ~BitcoinExchange();

    void convert(std::string inFile);

};

std::ostream &operator<<(std::ostream &output, const BitcoinExchange &input);

# endif