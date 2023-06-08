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
            std::cout << "Type A is generated. Address: " << ptr << std::endl;
            break;
        case 1:
            ptr = new B;
            std::cout << "Type B is generated. Address: " << ptr << std::endl;
            break;
        case 2:
            ptr = new C;
            std::cout << "Type C is generated. Address: " << ptr << std::endl;
            break;
    }
    return (ptr);
}

void identify(Base *ptr) {
    A   *Aptr = dynamic_cast<A *>(ptr);
    B   *Bptr = dynamic_cast<B *>(ptr);
    C   *Cptr = dynamic_cast<C *>(ptr);

    if (Aptr)
        std::cout << "Type is A. Address: " << Aptr << std::endl;
    else if (Bptr)
        std::cout << "Type is B. Address: " << Bptr << std::endl;
    else if (Cptr)
        std::cout << "Type is C. Address: " << Cptr << std::endl;
    else
        std::cerr << "Input is not of the types A, B or C." << std::endl;
}

void identify(Base &ref) {
    try
    {
        A   &Aref = dynamic_cast<A &>(ref);
        std::cout << "Type is A. Address: " << &Aref << std::endl;
    }
    catch(std::exception &e)
    {
        try
        {
            B   &Bref = dynamic_cast<B &>(ref);
            std::cout << "Type is B. Address: " << &Bref << std::endl;
        }
        catch(std::exception &e)
        {
            try
            {
                C   &Cref = dynamic_cast<C &>(ref);
                std::cout << "Type is C. Address: " << &Cref << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << "Input is not of the types A, B or C." << std::endl;
            }
        }
    }

}