#include "Array.hpp"

template<class T>
Array<T>::Array(): _size(0), _values(NULL) {}

template<class T>
Array<T>::Array(unsigned int size): _size(size), _values(new T[size]) {}

template<class T>
Array<T>::Array(Array const &src) {*this = src;}

template<class T>
Array<T> &Array<T>::operator=(Array<T> const &src) {
    _size = src.size();
    if(_values)
        delete [] _values;
    _values = new T[src.size()];
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