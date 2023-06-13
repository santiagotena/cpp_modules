/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:17:28 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/13 14:17:29 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
    std::string partition(30, '-');

    std::cout << partition << std::endl;
    std::cout << "// MUTANT STACK //" << std::endl;
    std::cout << partition << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);

    }
    std::cout << partition << std::endl;
    std::cout << "// LIST //" << std::endl;
    std::cout << partition << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }
    std::cout << partition << std::endl;
    std::cout << "// FURTHER TESTING //" << std::endl;
    std::cout << partition << std::endl;
    {
        MutantStack<int> k;
        std::stack<int> j;

        std::cout << "Stack size: " << j.size() << std::endl;
        std::cout << "MutantStack size: " << k.size() << std::endl;
        k.push(19);
        k.push(8);
        k.push(9);
        k.push(10);
        k.push(32);
        k.push(99);
        j.push(19);
        j.push(8);
        j.push(9);
        j.push(10);
        j.push(32);
        j.push(99);
        std::cout << "Stack size after adding elements: ";
        std::cout << j.size() << std::endl;
        std::cout << "MutantStack size after adding elements: ";
        std::cout << k.size() << std::endl;
        std::cout << "First element: ";
        std::cout << *(k.begin()) << std::endl;
        std::cout << "Last element: ";
        std::cout << *(k.end() - 1)<< std::endl;
    }
    std::cout << partition << std::endl;
    return (0);
}
