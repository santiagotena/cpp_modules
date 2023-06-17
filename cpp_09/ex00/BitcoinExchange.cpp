/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:37 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string referenceFile) {
    std::fstream file(referenceFile);
    if (file.fail()) {
        std::cerr << "Error: Cannot open reference file." << std::endl;
        return;
    }
    std::string buffer;
    Date date;
    while (getline(file, buffer)) {
        if (buffer != "date,exchange_rate") {
            size_t comaPos = buffer.find(',');
            date = createDate(buffer);
            bitcoinDB.insert(std::make_pair(date, stof(buffer.substr(comaPos + 1, buffer.length()))));
        }
    }
}

BitcoinExchange::~BitcoinExchange() {}

void printResult(double value, double amount, Date time) {
    std::cout << time << " => " << amount << " = " << value << std::endl;
}

void BitcoinExchange::_findRate(double amount, Date time) {
    for (std::map<Date, double>::iterator it = bitcoinDB.begin(); it != bitcoinDB.end(); it++)
    {
        if (it->first == time)
            return printResult(it->second * amount, amount, time);
        if (it->first > time)
            return printResult((--it)->second * amount, amount, time);
    }
}

void BitcoinExchange::convert(std::string inFile) {
    std::fstream file(inFile);
    if (file.fail()) {
        std::cerr << "Error: Cannot open reference file." << std::endl;
        return;
    }
    std::string buffer;
    Date date;
    double amount;
    while (getline(file, buffer)) {
        if (buffer != "date | value") {
            date = createDate(buffer);
            if(!date.isDateValid())
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            size_t pipePos = buffer.rfind(' ') + 1;
            amount = stof(buffer.substr(pipePos, buffer.length()));
            if (amount <= 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            else if(amount > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            _findRate(amount, date);
        }
    }
}

std::ostream &operator<<(std::ostream &output, const BitcoinExchange &input) {
    output << "BitcoinExchange database:" << std::endl;
    std::map<Date, double>::const_iterator it;
    for (it = input.bitcoinDB.begin(); it != input.bitcoinDB.end(); ++it) {
        output << it->first << " : " << it->second << '\n';
    }
    return output;
}
