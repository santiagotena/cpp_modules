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
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// BASE TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << meta->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        meta->makeSound();
        j->makeSound();
        i->makeSound(); //will output the cat sound!
        delete meta;
        delete j;
        delete i;
    }
    std::cout << partition << std::endl;
    std::cout << "// WRONG DESTRUCTION //" << std::endl;
    std::cout << partition << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* j = new WrongCat();
        const WrongCat* i = new WrongCat();
        std::cout << meta->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        meta->makeSound();
        j->makeSound();
        i->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    std::cout << partition << std::endl;
    std::cout << "// SOUND TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Animal animal;
        Dog dog;
        Cat cat;

        animal.makeSound();
        dog.makeSound();
        cat.makeSound();
    }
    std::cout << partition << std::endl;
    std::cout << "// DESTRUCTION TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Cat cat;

        std::cout << cat.getType() << std::endl;
        cat.makeSound();

        Cat* gato = new Cat;

        std::cout << gato->getType() <<std::endl;
        gato->makeSound();
        delete gato;
    }
    std::cout << partition << std::endl;
    return (0);
}
