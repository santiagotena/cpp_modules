/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:46:22 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/07 17:46:23 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src) {
    (void)src;
    *this = src;
}

Serializer &Serializer::operator=(Serializer const &src) {
    (void)src;
    return (*this);
}

Serializer::~Serializer() {}

uintptr_t   Serializer::serialize(Data *ptr) {
    uintptr_t   address = reinterpret_cast<uintptr_t>(ptr);
    return (address);
}

Data        *Serializer::deserialize(uintptr_t raw) {
    Data *tmp = reinterpret_cast<Data *>(raw);
    return (tmp);
}
