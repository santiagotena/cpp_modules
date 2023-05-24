/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:05:35 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 10:43:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        std::cout << "// BASE TESTS //" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
    }
    {
        std::cout << std::string(50, '-') << std::endl;
        std::cout << "// SOUND TESTS //" << std::endl;
        Animal animal;
        Dog dog;
        Cat cat;

        animal.makeSound();
        dog.makeSound();
        cat.makeSound();
    }
    return (0);
}
