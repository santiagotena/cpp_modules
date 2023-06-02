/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:56 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/28 16:18:55 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// BASE TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    std::cout << partition << std::endl;
    std::cout << "// DISPLAY TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Character zack("Zack");
        Character aeris("Aeris");
        zack.equip(new Ice());
        zack.equip(new Cure);
        zack.equip(new Ice());
        zack.displayInventory();
        zack.displayStorage();
        zack.unequip(2);
        zack.displayInventory();
        zack.displayStorage();
        zack.use(1, aeris);
    }
    std::cout << partition << std::endl;
    std::cout << "// CLONE TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Character soldier("Soldier");
        MateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->displayMemory();
        AMateria* tmp;
        tmp = src->createMateria("ice");
        soldier.equip(tmp);
        tmp = src->createMateria("cure");
        soldier.equip(tmp);
        soldier.displayInventory();
        soldier.displayStorage();

        std::cout << std::endl;
        std::cout << "Soldier Copy Constructor Test:" << std::endl;
        std::cout << partition << std::endl;
        Character soldier2(soldier);
        soldier2.unequip(1);
        soldier.displayInventory();
        soldier.displayStorage();
        std::cout << std::endl;
        soldier2.displayInventory();
        soldier2.displayStorage();

        std::cout << std::endl;
        std::cout << "Soldier Copy Assignment Constructor Test:" << std::endl;
        std::cout << partition << std::endl;
        Character soldier3 = soldier;
        tmp = src->createMateria("cure");
        soldier3.equip(tmp);
        soldier.displayInventory();
        soldier.displayStorage();
        std::cout << std::endl;
        soldier3.displayInventory();
        soldier3.displayStorage();

        delete src;
    }
    std::cout << partition << std::endl;
    std::cout << "// EQUIP NULL //" << std::endl;
    std::cout << partition << std::endl;
    {
        Character tifa("Tifa");
        MateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->displayMemory();
        AMateria* tmp;
        tmp = src->createMateria("ice");
        tifa.equip(tmp);
        tmp = src->createMateria("wrong");
        tifa.equip(tmp);
        tifa.displayInventory();
        tifa.displayStorage();

        delete src;
    }
    std::cout << partition << std::endl;
    std::cout << "// OVER-EQUIP //" << std::endl;
    std::cout << partition << std::endl;
    {
        Character cloud("Cloud");
        MateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->displayMemory();
        AMateria* tmp;
        tmp = src->createMateria("ice");
        cloud.equip(tmp);
        tmp = src->createMateria("cure");
        cloud.equip(tmp);
        tmp = src->createMateria("ice");
        cloud.equip(tmp);
        tmp = src->createMateria("cure");
        cloud.equip(tmp);
        tmp = src->createMateria("ice");
        cloud.equip(tmp);
        cloud.displayInventory();
        cloud.displayStorage();

        delete src;
        delete tmp;
    }
    std::cout << partition << std::endl;
    return 0;
}
