/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:24:21 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/13 12:24:22 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N): _maximumCollectionSize(N), _currentCollectionSize(0) {}

Span::Span(Span const &src) {*this = src;}

Span    &Span::operator=(Span const &src) {
    _integerCollection = src._integerCollection;
    _maximumCollectionSize = src._maximumCollectionSize;
    _currentCollectionSize = src._currentCollectionSize;
    return (*this);
}

Span::~Span() {}

void    Span::addNumber(int number) {
    unsigned int copyCurrentCollectionSize = _currentCollectionSize;
    _currentCollectionSize++;
    if (_currentCollectionSize > _maximumCollectionSize) {
        _currentCollectionSize = copyCurrentCollectionSize;
        throw CollectionIsFullException();
    }
    _integerCollection.push_front(number);
}

void    Span::addNumberRange(int startOfRange, int endOfRange) {
    if (startOfRange >= endOfRange) {
        std::cerr << "Error: startOfRange must be smaller than endOfRange." << std::endl;
        return;
    }
    unsigned int copyCurrentCollectionSize = _currentCollectionSize;
    _currentCollectionSize += endOfRange - startOfRange + 1;
    if (_currentCollectionSize > _maximumCollectionSize) {
        _currentCollectionSize = copyCurrentCollectionSize;
        throw CollectionIsFullException();
    }
    for (int i = startOfRange; i <= endOfRange; i++)
        _integerCollection.push_front(i);
}

int     Span::shortestSpan() const {
    if (_currentCollectionSize < 2)
        throw NotEnoughElementsException();

    int shortestSpan = INT_MAX;
    std::deque<int>::const_iterator outerIterator = _integerCollection.begin();
    std::deque<int>::const_iterator innerIterator;
    std::deque<int>::const_iterator end = _integerCollection.end();

    for(; outerIterator != end; outerIterator++) {
        innerIterator = outerIterator + 1;
        for (; innerIterator != end; innerIterator++) {
            if (std::abs(*outerIterator - *innerIterator) < shortestSpan)
                shortestSpan = std::abs(*outerIterator - *innerIterator);
        }
    }
    return (shortestSpan);
}

int     Span::longestSpan() const {
    if (_currentCollectionSize < 2)
        throw NotEnoughElementsException();

    int longestSpan = 0;
    std::deque<int>::const_iterator outerIterator = _integerCollection.begin();
    std::deque<int>::const_iterator innerIterator;
    std::deque<int>::const_iterator end = _integerCollection.end();

    for(; outerIterator != end; outerIterator++) {
        innerIterator = outerIterator + 1;
        for (; innerIterator != end; innerIterator++) {
            if (std::abs(*outerIterator - *innerIterator) > longestSpan)
                longestSpan = std::abs(*outerIterator - *innerIterator);
        }
    }
    return (longestSpan);
}

const char	*Span::CollectionIsFullException::what() const throw(){
    return "Exception: Integer collection is full, no more elements can be added.";
}

const char	*Span::NotEnoughElementsException::what() const throw(){
    return "Exception: Not enough elements present.";
}