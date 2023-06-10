#include <iostream>

class Parent                {};
class Child1: public Parent {};
class Child2: public Parent {};

class Unrelated             {};

int main() {
    Child1      a;                                  //Reference value

    Parent      *b = &a;                            //Implicit upcast -> Ok
    Child1      *c = b;                             //Implicit downcast -> Not allowed
    Child2      *d = static_cast<Child2 *>(b);      //Explicit downcast -> Ok, it is possible

    Unrelated   *e = static_cast<Unrelated *>(&a);  //Explicit conversion -> No!

    return (0);
}