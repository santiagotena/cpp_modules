/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:37 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include "BitcoinExchange.hpp"

class Date {
private:
    int _day;
    int _month;
    int _year;

public:
    Date();
    Date(int day, int month, int year);
    ~Date();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool operator==(Date const &src) const;
    bool operator!=(Date const &src) const;
    bool operator<(Date const &src) const;
    bool operator>(Date const &src) const;
    bool operator<=(Date const &src) const;
    bool operator>=(Date const &src) const;

    bool isDateValid();

    class IncorectDateFormat : public std::exception
    {
    public:
        const char* what() const throw ()
        {
            return "Exception: Invalid Date Format.";
        }
    };
};

std::ostream &operator<<(std::ostream &output, Date date);

#endif