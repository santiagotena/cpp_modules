/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:46:45 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/13 14:46:46 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(): _size(0), _values(new T[0]) {}

template<typename T>
Array<T>::Array(unsigned int size): _size(size), _values(new T[size]) {}

template<typename T>
Array<T>::Array(Array const &src): _size(0), _values(new T[0]) {*this = src;}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &src) {
    _size = src.size();
    if(_values)
        delete [] _values;
    _values = new T[src.size()];
    for (size_t i = 0; i < _size; i++)
        _values[i] = src[i];
    return (*this);
}

template<typename T>
Array<T>::~Array() {
    delete[] _values;
}

template<typename T>
T &Array<T>::operator[](size_t index) const
{
    if(index < _size)
        return _values[index];
    else
        throw OutOfBoundsException();
}

template<typename T>
unsigned int Array<T>::size() const{return _size;}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw(){
    return "Exception: Index is out of bounds.";
}