/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:46:28 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/07 17:46:30 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    std::string partition(50, '-');

    Data    sample;
    sample.random = 42;
    sample.random_str = "Random";

    std::cout << partition << std::endl;
    std::cout << "// BASE VALUES //" << std::endl;
    std::cout << partition << std::endl;
    std::cout <<    "Address: " << &sample << std::endl <<
                    "Content: " << sample.random << "  " << sample.random_str << std::endl;
    std::cout << std::endl;

    std::cout << partition << std::endl;
    std::cout << "// SERIALIZED VALUES //" << std::endl;
    std::cout << partition << std::endl;
    uintptr_t tmp = Serializer::serialize(&sample);
    std::cout <<    "Address: " << &tmp << std::endl <<
                    "Content: " << tmp << std::endl;
    std::cout << std::endl;

    std::cout << partition << std::endl;
    std::cout << "// DESERIALIZED VALUES //" << std::endl;
    std::cout << partition << std::endl;
    Data sample2;
    sample2 = *Serializer::deserialize(tmp);
    std::cout <<    "Address: " << &sample2 << std::endl <<
                    "Content: " << sample2.random << "  " << sample2.random_str << std::endl;
    std::cout << std::endl;

    return (0);
}