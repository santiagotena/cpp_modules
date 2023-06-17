/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:37 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() {}

Date::Date(int day, int month, int year): _day(day), _month(month), _year(year) {}

Date::~Date() {}

bool Date::operator==(Date const &src) const {
    return (_day == src._day &&
           _month == src._month &&
           _year == src._year);
}

bool Date::operator!=(Date const &src) const {
    return !(*this == src);
}

bool Date::operator<(Date const &src) const {
    if (_year < src._year)
        return (true);
    else if (_year == src._year) {
        if (_month < src._month)
            return (true);
        else if (_month == src._month) {
            if (_day < src._day) {
                return (true);
            }
            else
                return (false);
        }
    }
    return (false);
}

int Date::getDay() const {return (_day);}

int Date::getMonth() const {return (_month);}

int Date::getYear() const {return (_year);}

bool Date::operator>(Date const &src) const {
    return (src < *this);
}

bool Date::operator<=(Date const &src) const {
    return !(src < *this);
}

bool Date::operator>=(Date const &src) const {
    return !(*this < src);
}

bool Date::isDateValid(){
    return (_day > 0 && _day <= 31 && _month > 0 && _month <= 12 && _year > 0  );
}

Date createDate(std::string str) {
    int _day, _month, _year;
    _year = stoi(str);
    size_t index = str.find('-');
    if (index != 4)
        throw Date::IncorectDateFormat();
    str = str.erase(0, 5);
    _month = stoi(str);
    index = str.find('-');
    str = str.erase(0, 3);
    if (index != 2)
        throw Date::IncorectDateFormat();
    _day = stoi(str);
    Date date(_day, _month, _year);
    return (date);
}

std::ostream &operator<<(std::ostream &output, Date date) {
    output << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
    return output;
}
