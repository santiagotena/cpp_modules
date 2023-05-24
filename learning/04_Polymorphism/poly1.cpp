#include <string>
#include <iostream>

class Character
{
public:
    void    sayHello(std::string const &target);
};

class Warrior : public Character
{
public:
    void sayHello(std::string const &target);
};

class Cat
{
//    [...]
};

void    Character::sayHello(std::string const &target)
{
    std::cout << "Hello " << target << " !" << std::endl;
}

void    Warrior::sayHello(std::string const &target)
{
    std::cout << "I am here to fight " << target << std::endl;
}

int main(void)
{
//    A Warrior is a Warrior
    Warrior *a = new Warrior();

//    A Warrior is a Character
    Character   *b = new Warrior();

//    A Character is not a Warrior. This will not compile.
//    Warrior is a Character but the reverse is no true
//    Warrior *c = new Character();

//    A Cat is not a Character. This will not compile.
//    The classes are not related at all.
//    Character   *d = new Cat();

    a->sayHello("students");
    b->sayHello("students");

    return (0);
}