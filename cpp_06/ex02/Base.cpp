/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:33:43 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/07 23:33:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base    *generate() {
    Base *ptr;

    srand(time(NULL));
    int i = rand();
    switch(i % 3)
    {
        case 0:
            ptr = new A;
            std::cout << "Type A is generated." << std::endl;
            break;
        case 1:
            ptr = new B;
            std::cout << "Type B is generated." << std::endl;
            break;
        case 2:
            ptr = new C;
            std::cout << "Type C is generated." << std::endl;
            break;
    }
    return (ptr);
}

void identify(Base *ptr) {
    if (dynamic_cast<A*>(ptr) != NULL)
        std::cout << "Type is A" << std::endl;
    else if (dynamic_cast<B*>(ptr) != NULL)
        std::cout << "Type is B" << std::endl;
    else if (dynamic_cast<C*>(ptr) != NULL)
        std::cout << "Type is C" << std::endl;
}

void identify(Base &ref) {
    if (dynamic_cast<A*>(&ref) != NULL)
        std::cout << "Type is A" << std::endl;
    else if (dynamic_cast<B*>(&ref) != NULL)
        std::cout << "Type is B" << std::endl;
    else if (dynamic_cast<C*>(&ref) != NULL)
        std::cout << "Type is C" << std::endl;
}