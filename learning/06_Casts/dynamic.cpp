#include <iostream>
#include <typeinfo>
#include <exception>

class Parent                {public: virtual ~Parent() {}};
class Child1: public Parent {};
class Child2: public Parent {};

int main() {
    Child1  a;
    Parent  *b = &a;

    //Explicit downcast
    Child1  *c = dynamic_cast<Child1 *>(b);
    if (c == NULL)
        std::cout << "Conversion is not Ok" << std::endl;
    else
        std::cout << "Conversion is Ok" << std::endl;

    //Explicit downcast
    try {
        Child2 &d = dynamic_cast<Child2 &>(*b);
        std::cout << "Conversion is Ok" << std::endl;
    }
    catch (std::bad_cast &bc) {
        std::cout << "Conversion is not Ok" << std::endl;
        return (0);
    }

    return (0);
};