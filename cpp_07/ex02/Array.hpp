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

# include <exception>

template<typename T>
class Array {
private:
    T               *_values;
    unsigned int    _size;

public:
    Array();
    Array(unsigned int size);
    Array(Array<T> const &src);
    Array &operator=(Array<T> const &src);
    ~Array();

    T               &operator[](size_t index) const;
    unsigned int    size() const;

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char	*what() const throw();
    };
};
# include "Array.tpp"

#endif