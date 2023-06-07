/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:46:20 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/07 17:46:22 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

typedef struct data
{
    int             random;
    std::string     random_str;
} Data;

class Serializer {
private:
    Serializer();
    Serializer(Serializer const &src);
    Serializer &operator=(Serializer const &src);
    ~Serializer();

public:
    static uintptr_t   serialize(Data *ptr);
    static Data        *deserialize(uintptr_t raw);
};

#endif