#include <string>
#include <iostream>

class ACharacter
{
    private:
        std::string     _name;

    public:
        virtual void    attack(std::string const &target) = 0; // This is a pure function
        void            sayHello(std::string const &target);
};

class Warrior : public ACharacter
{
    public:
        virtual void    attack(std::string const &target);
};

void    ACharacter::sayHello(std::string const &target)
{
    std::cout << "Hello " << target << " !" << std::endl;
}

void    Warrior::attack(std::string const &target)
{
    std::cout << "*Warrior attacks " << target << " with a sword*" << std::endl;
}

//class   ICoffeeMaker
//{
//    public:
//        virtual void        fillWaterTank(IWaterSource *src) = 0;
//        virtual ICoffe      *makeCoffee(std::string const &type) = 0;
//};

int main(void)
{
    ACharacter  *a = new Warrior();

//    ACharacter is abstract. This will not compile
//    ACharacter  *b = new ACharacter();

    a->sayHello("students");
    a->attack("Jora");
}
