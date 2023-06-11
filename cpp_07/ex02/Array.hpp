/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:49:09 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/09 11:49:10 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<class T>
class Array {
private:
    T   *_values;
    unsigned int _size;

public:
    Array();
    Array(unsigned int size);
    Array(Array<T> const &src);
    Array &operator=(Array<T> const &src);
    ~Array();

    T               &operator[](size_t index) const;
    unsigned int    size() const;
};

template<class T>
Array<T>::Array() {
    _size = 0;
    _values = new T[_size];
}

template<class T>
Array<T>::Array(unsigned int size) {
    _size = size;
    _values = new T[_size];
}

template<class T>
Array<T>::Array(Array const &src) {*this = src;}

template<class T>
Array<T> &Array<T>::operator=(Array<T> const &src) {
    _size = src.size();
    if(_values)
        delete [] _values;
    _values = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _values[i] = src[i];
    return (*this);
}

template<class T>
Array<T>::~Array() {
    delete[] _values;
}

template<class T>
T &Array<T>::operator[](size_t index) const
{
    if(index < _size)
        return _values[index];
    else
        throw std::out_of_range("Exception: Index is out of bounds.");
}

template<class T>
unsigned int Array<T>::size() const{return _size;}

#endif