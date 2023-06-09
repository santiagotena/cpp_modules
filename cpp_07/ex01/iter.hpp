/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:48:53 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/09 11:48:54 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T *array, int len, void (*function)(T &param))
{
    for (int i = 0; i < len; i++)
        function(array[i]);
}

template<typename T>
void print(T &element)
{
    std::cout << element << std::endl;
}

template<typename T>
void square(T &element)
{
    element*=element;
}

#endif