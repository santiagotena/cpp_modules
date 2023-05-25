/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:08:26 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/25 10:08:27 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// BASE TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }
    std::cout << partition << std::endl;
    std::cout << "// DEEP COPIES //" << std::endl;
    std::cout << partition << std::endl;
    {
        Dog dog;
        Dog perro(dog);

        dog.setIdea(0, "Who is a good boy?");
        perro.setIdea(0, "Ball!");
        std::cout << dog.getIdea(0) << std::endl;
        std::cout << perro.getIdea(0) << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// ANIMAL ARRAY //" << std::endl;
    std::cout << partition << std::endl;
    {
        int size = 4;
        Animal  *pets[size];

        for (int i = 0; i < size/2; i++)
            pets[i] = new Dog();
        for (int i = size/2; i < size; i++)
            pets[i] = new Cat();
        std::cout << pets[0]->getType() << std::endl;
        std::cout << pets[size - 1]->getType() << std::endl;
        for (int i = 0; i < size; i++)
            delete pets[i];
    }
    std::cout << partition << std::endl;
    return (0);
}
