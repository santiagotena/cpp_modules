/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:24:23 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/13 12:24:24 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <deque>
//#include <exception>

class Span {
private:
    std::deque<int>     _integerCollection;
    unsigned int        _maximumCollectionSize;
    unsigned int        _currentCollectionSize;

    Span();

public:
    Span(unsigned int N);
    Span(Span const &src);
    Span &operator=(Span const &src);
    ~Span();

    void    addNumber(int number);
    void    addNumberRange(int startOfRange, int endOfRange);

    int     shortestSpan() const;
    int     longestSpan() const;

    class CollectionIsFullException : public std::exception
    {
    public:
        const char	*what() const throw();
    };

    class NotEnoughElementsException : public std::exception
    {
    public:
        const char	*what() const throw();
    };
};

#endif