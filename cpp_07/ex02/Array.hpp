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
# include "Array.tpp"


template<class T>
class Array {
private:
    T   *_array;
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
Array<T>::Array(): _array(NULL), _size(0) {}

template<class T>
Array<T>::Array(unsigned int size): _size(size) {
    _array = new T[size];
}

template<class T>
Array<T>::Array(Array const &src) {*this = src;}

template<class T>
Array<T> &Array<T>::operator=(Array<T> const &src) {
    if(_array)
        delete [] _array;
    _array = new T [src.size()];
    _size = src.size();
    for (size_t i = 0; i < _size; i++)
        _array[i] = src[i];
    return (*this);
}

template<class T>
Array<T>::~Array() {
    delete[] _array;
}

template<class T>
T &Array<T>::operator[](size_t index) const
{
    if(index < _size)
        return _array[index];
    else
        throw std::out_of_range("Exception: Index is out of bounds.");
}

template<class T>
unsigned int Array<T>::size() const{return _size;}

#endif