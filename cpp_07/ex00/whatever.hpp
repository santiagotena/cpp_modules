/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:15:51 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/09 11:15:52 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
    T   temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T &min(T &a, T &b)
{
    return (a < b ? a : b);
}

template <typename T>
T &max(T &a, T &b)
{
    return (a > b ? a : b);
}

#endif